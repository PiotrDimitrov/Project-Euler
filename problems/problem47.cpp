/*
   The first two consecutive numbers to have two distinct prime factors are:

   14 = 2 × 7
   15 = 3 × 5

   The first three consecutive numbers to have three distinct prime factors
   are:

   644 = 2² × 7 × 23
   645 = 3 × 5 × 43
   646 = 2 × 17 × 19.

   Find the first four consecutive integers to have four distinct prime
   factors. What is the first of these numbers?
 */
#include <vector>

namespace pr47 {
    bool isIn(int num, std::vector<int> vec){
        for (auto e : vec){
            if (e == num) {return true;}
        }
        return false;
    }
    int factors(int x){
        std::vector <int> factor;
        int res = 0;
        while (x > 1) {
            for (int i = 2; i <= x; i++){
                if (x % i == 0){
                    if (!pr47::isIn(i, factor)) {factor.push_back(i); res++;}
                    x = x / i;
                    break;
                }
            }
        }
        return res;
    }
}

int problem47() {
    int n1, n2, n3, n4, next;
    n1 = pr47::factors(1000);
    n2 = pr47::factors(1001);
    n3 = pr47::factors(1002);
    n4 = pr47::factors(1003);
    for (int i = 1004; i <= 999999; i++){
        if (n1 == n2 && n2 == n3 && n3 == n4 && n1 == 4) {return i-4;}
        n1 = n2;
        n2 = n3;
        n3 = n4;
        n4 = pr47::factors(i);;
    }
    return -1;
} //134043
