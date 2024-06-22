/*
   A googol (10^100) is a massive number: one followed by one-hundred zeros;
   100^100 is almost unimaginably large: one followed by two-hundred zeros.
   Despite their size, the sum of the digits in each number is only 1.

   Considering natural numbers of the form, a^b, where a, b < 100, what is
   the maximum digital sum?
 */

#include "../libs/bigNum.h"

namespace pr56 {
    int sumOfDigigts(const bigNum& n){
        int res = 0;
        for (int e : n.digits){
            res += e;
        }
        return res;
    }
}

int problem56() {
    int result = 0;
    for (bigNum n = 2; n <= 100; n = n + 1){
        bigNum current = n;
        int c = 100;
        while (c--){
            if (pr56::sumOfDigigts(current) > result){result = pr56::sumOfDigigts(current);}
            current = current * n;
        }
    }
    return result;
}