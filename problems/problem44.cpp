/*
   Pentagonal numbers are generated by the formula, P[n]=n(3n−1)/2. The first
   ten pentagonal numbers are:

                  1, 5, 12, 22, 35, 51, 70, 92, 117, 145, ...

   It can be seen that P[4] + P[7] = 22 + 70 = 92 = P[8]. However, their
   difference, 70 − 22 = 48, is not pentagonal.

   Find the pair of pentagonal numbers, P[j] and P[k], for which their sum
   and difference are pentagonal and D = |P[k] − P[j]| is minimised; what is
   the value of D?
 */
#include <cmath>

namespace pr44{
    bool isPentagonal(unsigned long long x)
    {
        unsigned long long n = (1 + sqrt(24*x + 1)) / 6;
        auto p_n = n * (3 * n - 1) / 2;
        return p_n == x;
    }
    int pent(int x){
        return x*(3*x-1)/2;
    }
}

int problem44() {
    int first, second;
    for (int sum = 3; sum < 100000; sum++){
        second = 1;
        first = sum - second;
        while (first > second){
            int d = pr44::pent(first) - pr44::pent(second);
            int s = pr44::pent(first) + pr44::pent(second);
            //if (pr44::isPent(d) && pr44::isPent(s)){return d;}
            if (pr44::isPentagonal(d) && pr44::isPentagonal(s)){return d;}
            first--; second++;
        }
    }
    return -1;
}