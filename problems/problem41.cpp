/*
   We shall say that an n-digit number is pandigital if it makes use of all
   the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital
   and is also prime.

   What is the largest n-digit pandigital prime that exists?
 */
#include <vector>
#include <iostream>

namespace pr41 {
    bool isPrime(int x){
        for (int i = 2; i * i <= x; i++){
            if (x % i == 0) {return false;}
        }
        return true;
    }

    bool isPandig(int x){
        std::vector<int> vec(10, 0);
        int len = 0;
        while (x > 0){
            vec[x%10]++;
            x /= 10;
            len++;
        }
        if (vec[0] > 0) {return false;}
        for (int i = 1; i < len+1; i++){
            if (vec[i] != 1) {return false;}
        }
        return true;
    }
}


long problem41 () {
    int result = 0;
    for (long i = 7654321; i > 0; i--){
        // it's useless to check 987654321 and 87654321 (and its permutations)
        // as both pandigitals are divisable by 3 (by sum of digits), thus not prime
        if (pr41::isPrime(i) && pr41::isPandig(i)){result = i; break;}
    }
    return result;
}