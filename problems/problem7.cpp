/*
   By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see
   that the 6th prime is 13.

   What is the 10 001st prime number?
*/

#include <cmath>

namespace pr7 {
    bool isPrime(int x){
        for (int i = 2; i <= sqrt(x); ++i){
            if (x % i == 0) {return false;}
        }
        return true;
    }
}

int problem7() {
    int counter = 1;
    int num = 1;
    while (counter < 10001) {
        num += 2;
        if (pr7::isPrime(num)) {counter++;}
    }
    return num;
}