/*
   If p is the perimeter of a right angle triangle with integral length
   sides, {a,b,c}, there are exactly three solutions for p = 120.

   {20,48,52}, {24,45,51}, {30,40,50}

   For which value of p ≤ 1000, is the number of solutions maximised?
 */
#include <vector>
#include <cmath>

namespace pr39 {
    int intSqrt(int x) {
        int i;
        for (i = 1; i * i <= x; i++) {}
        --i;
        if (i * i == x) { return i; }
        else { return -1; }
    }
}

int problem39() {
    int result = 0;
    int max = 0;
    std::vector<int> vec (1000, 0);
    for (int a = 1; a < 500; ++a){
        for (int b = 1; b < 500-a; ++b){
            int c2 = a*a + b*b;
            int c = pr39::intSqrt(c2);
            if (c > 0 && a+b+c < 1000){
                vec[a+b+c]++;
                if (vec[a+b+c] > max) {max = vec[a+b+c]; result = a+b+c;}
            }
        }
    }
    return result;
}