/*
   It was proposed by Christian Goldbach that every odd composite number can
   be written as the sum of a prime and twice a square.

   9 = 7 + 2×1^2
   15 = 7 + 2×2^2
   21 = 3 + 2×3^2
   25 = 7 + 2×3^2
   27 = 19 + 2×2^2
   33 = 31 + 2×1^2

   It turns out that the conjecture was false.

   What is the smallest odd composite that cannot be written as the sum of a
   prime and twice a square?
 */
#include <vector>
#include <cmath>

namespace pr46 {
    void sieve(std::vector<int> &vec){
        for (int i = 2; i*i <= vec.size(); i++){
            if (vec[i] == 0) { continue;}
            for (int j = 2*vec[i]; j < vec.size(); j+=vec[i]){
                vec[j] = 0;
            }
        }
    }
    bool isSqr(int x){
        int n = sqrt(x);
        return x == n*n;
    }
}

int problem46() {
    std::vector<int> vec;
    vec.reserve(6000);
    for (int i = 0; i < 6000; i++){
        vec.push_back(i);
    }
    pr46::sieve(vec);
    for (int x = 3; x < 1000000; x+=2){
        bool flag = false;
        for (int & prime : vec){
            if (prime <= 1){ continue;}
            if (x == prime) {flag = true; break;}
            if (pr46::isSqr((x - prime) / 2)) {flag = true;}

        }
        if (!flag) {return x;}
    }
}