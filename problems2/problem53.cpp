/*
   There are exactly ten ways of selecting three from five, 12345:

              123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

   In combinatorics, we use the notation, ^5C[3] = 10.

   In general,

      ^nC[r] =    n!    ,where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.
               r!(n−r)!

   It is not until n = 23, that a value exceeds one-million: ^23C[10] =
   1144066.

   How many, not necessarily distinct, values of ^nC[r], for 1 ≤ n ≤ 100,
   are greater than one-million?
 */
#include <cmath>

namespace pr53 {
    int combinations(int n, int r){
        double result = 1.0;
        int m = std::max(r, n-r);
        auto* nums = new double[n-m];

        for (double i = n*1.0; i > m; i -= 1.0){
            nums[int(n-i)] = i;
        }
        for (double i = n-m*1.0; i >= 1.0; i -= 1.0){
            nums[int(n - m - i)] = nums[int(n - m - i)]*1.0 / i;
        }
        for (int x = 0; x < n-m; x++){
            double temp = nums[x];
            result *= temp;
            if (result > 1000000){delete [] nums; return -1;}
        }
        delete [] nums;
        return round(result);
    }
}

int problem53() {
    int result = 0;
    for (int n = 1; n <= 100; n++){
        for (int r = 0; r <= n; r++){
            if (pr53::combinations(n, r) == -1) {result++;}
        }
    }
    return result;
    //return pr53::combinations(100, 50);
}