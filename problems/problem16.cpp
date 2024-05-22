/*
   2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

   What is the sum of the digits of the number 2^1000?
*/
#include "../libs/bigNum.h"

int problem16() {
    bigNum num = bigNum::toBN(2) ^ bigNum::toBN(1000);
    int result = 0;
    for (int e : num.digits) {
        result += e;
    }
    return result;
}