/*
   n! means n × (n − 1) × ... × 3 × 2 × 1

   For example, 10! = 10 × 9 × ... × 3 × 2 × 1 = 3628800,
   and the sum of the digits in the number 10! is 3 + 6 + 2 + 8 + 8 + 0 + 0 =
   27.

   Find the sum of the digits in the number 100!
*/
#include "../libs/bigNum.h"

int problem20 () {
    bigNum num(1);
    for (int i = 1; i <= 100; i++){
        num = num * i;
    }
    int result = 0;
    for (int e : num.digits){
        result += e;
    }
    return result;
}