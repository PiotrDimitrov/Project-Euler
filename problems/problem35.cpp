/*
   The number, 197, is called a circular prime because all rotations of the
   digits: 197, 971, and 719, are themselves prime.

   There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37,
   71, 73, 79, and 97.

   How many circular primes are there below one million?
 */
#include <cmath>
#include <iostream>

namespace pr35 {
    bool isPrime(int x){
        for (int i = 2; i*i <= x; i++){
            if (x % i == 0) {return false;}
        }
        return true;
    }

    int len(int x){
        int res = 0;
        while (x > 0){
            res++;
            x /= 10;
        }
        return res;
    }
}

int problem35() {
    int result = 0;
    for (int i = 2; i < 1000000; i++){
        int flag = true;
        int num = i;
        while (num > 0){
            if (num % 10 == 0) {flag = false;}
            num /= 10;
        }
        num = i;
        for (int j = 0; j < pr35::len(i); j++){
            flag  = flag && pr35::isPrime(num);
            if (!flag) {break;}
            num = num % int(pow(10, pr35::len(num) - 1)) * 10 + num / int(pow(10, pr35::len(num) - 1));
        }
        if (flag) {result++;}
    }
    return result;
}