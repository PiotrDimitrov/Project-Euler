/*
   The number 3797 has an interesting property. Being prime itself, it is
   possible to continuously remove digits from left to right, and remain
   prime at each stage: 3797, 797, 97, and 7. Similarly we can work from
   right to left: 3797, 379, 37, and 3.

   Find the sum of the only eleven primes that are both truncatable from left
   to right and right to left.

   NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
 */
#include <cmath>
#include <iostream>

namespace pr37 {
    bool isPrime(int x){
        if (x <= 1){return false;}
        for (int i = 2; i * i <= x; i++){
            if (x % i == 0) {return false;}
        }
        return true;
    }

    int length(int x){
        int res = 0;
        while (x > 0){
            res++;
            x /= 10;
        }
        return res;
    }
}

int problem37() {
    int result = 0;
    for (int i = 11; i < 1000000; i++){
        int num = i;
        bool flag = true;
        while (num > 0){
            if (!pr37::isPrime(num)) {flag = false; break;}
            num /= 10;
        }
        if (!flag) {continue;}
        num = i;
        int power = pr37::length(num) - 1;
        while (true){
            num = num % int(pow(10, power));
            power--;
            if (num <= 0) {break;}
            if (!pr37::isPrime(num)) {flag = false; break;}
        }
        if (!flag) {continue;}
        else {result += i;}
    }
    return result;
}