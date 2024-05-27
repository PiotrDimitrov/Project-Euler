/*
   145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

   Find the sum of all numbers which are equal to the sum of the factorial of
   their digits.

   Note: as 1! = 1 and 2! = 2 are not sums they are not included.
 */
#include <iostream>
namespace pr34 {
    int fact(int x){
        if (x <= 1){return 1;}
        return x * fact(x-1);
    }

    int sumF(int x){
        int res = 0;
        while (x > 0){
            res += fact(x%10);
            x /= 10;
        }
        return res;
    }
}

int problem34() {
    int result = 0;
    for (int i = 3; i < pr34::fact(9); i++){
        if (pr34::sumF(i) == i) {result += i;}
    }
    return result;
}