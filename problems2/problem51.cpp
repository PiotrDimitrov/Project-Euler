/*
   By replacing the 1^st digit of the 2-digit number *3, it turns out that
   six of the nine possible values: 13, 23, 43, 53, 73, and 83, are all
   prime.

   By replacing the 3^rd and 4^th digits of 56**3 with the same digit, this
   5-digit number is the first example having seven primes among the ten
   generated numbers, yielding the family: 56003, 56113, 56333, 56443, 56663,
   56773, and 56993. Consequently 56003, being the first member of this
   family, is the smallest prime with this property.

   Find the smallest prime which, by replacing part of the number (not
   necessarily adjacent digits) with the same digit, is part of an eight
   prime value family.
 */

#include <vector>
#include <cmath>
#include <iostream>

namespace pr51 {
    int hasThree(int x){
        std::vector<int> vec(10, 0);
        while(x > 0){
            vec[x%10]++;
            x /= 10;
        }
        for (int i = 0; i < 10; ++i){
            if (vec[i] == 3) {return i;}
        }
        return -1;
    }

    bool isPrime(int x){
        for (int i = 2; i * i <= x; ++i){
            if (x % i == 0) {return false;}
        }
        return true;
    }

    int vecToInt(std::vector<int> vec){
        int res = 0;
        for (int i = 0; i < vec.size(); i++){
            res += vec[i] * pow(10, i);
        }
        return res;
    }

    std::vector<int> intToVec(int x){
        std::vector <int> vec;
        while (x > 0) {
            vec.push_back(x % 10);
            x /= 10;
        }
        return vec;
    }
}

int problem51() {
    std::vector<int> vec;
    vec.reserve(1000000);
    for (int i = 0; i < vec.capacity(); i++){
        vec.push_back(i);
    }

    for (int i = 2; i * i <= vec.size(); i++){
        if (vec[i] == 0){continue;}
        for (int j = vec[i]*vec[i]; j < vec.size(); j+=vec[i]){
            vec[j] = 0;
        }
    }

    for (int i = 100000; i < 1000000; ++i){
        if (vec[i] == 0){ continue;}
        int family = 0;
        int index = pr51::hasThree(vec[i]);

        if (index != -1) {
            std::vector<int> number = pr51::intToVec(vec[i]);
            std::vector<int> indexes(number.size(), 0);
            for (int n = 0; n < number.size(); n++){
                if (number[n] == index){
                    indexes[n] = 1;
                }
            }
            for (int digit = 1; digit <= 9; digit++){
                for (int i = 0; i < number.size(); i++){
                    if (indexes[i] == 1) {
                        number[i] = digit;
                    }
                }
                int temp = pr51::vecToInt(number);
                if (pr51::isPrime(temp)) { family++;}
            }
            if (family == 8) {return vec[i];}

        }
    }
    return -1;
}