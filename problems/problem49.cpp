/*
   The arithmetic sequence, 1487, 4817, 8147, in which each of the terms
   increases by 3330, is unusual in two ways: (i) each of the three terms are
   prime, and, (ii) each of the 4-digit numbers are permutations of one
   another.

   There are no arithmetic sequences made up of three 1-, 2-, or 3-digit
   primes, exhibiting this property, but there is one other 4-digit
   increasing sequence.

   What 12-digit number do you form by concatenating the three terms in this
   sequence?
 */

#include <vector>
#include <algorithm>
#include <string>

namespace pr49 {
    bool check(int n1, int n2, int n3){
        int arr1[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int arr2[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        int arr3[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
        while (n1 > 0 && n2 > 0 && n3 > 0){
            arr1[n1%10]++; arr2[n2%10]++; arr3[n3%10]++;
            n1 /= 10; n2 /= 10; n3 /= 10;
        }
        for (int i = 0; i < 10; i++){
            if (arr1[i] != arr2[i] || arr1[i] != arr3[i] || arr3[i] != arr2[i]){
                return false;
            }
        }
        return true;
    }
}

std::string problem49() {
    std::string result;
    std::vector<int> vec;
    vec.reserve(10000);
    for (int i = 0; i < 10000; i++) {vec.push_back(i);}
    for (int n = 2; n * n <= vec.size(); n++){
        if (vec[n] == 0) {continue;}
        for (int i = vec[n]*vec[n]; i < vec.size(); i+=vec[n]){
            vec[i] = 0;
        }
    }
    for (int i = 1000; i < vec.size(); i++){
        if (vec[i] == 0 || vec[i] == 1487) {continue;}
        for (int j = i+1; j < vec.size(); j++){
            if (vec[j] != 0 && j + j - i < vec.size() && vec[j + j - i] != 0){
                if (pr49::check(vec[i], vec[j], vec[j + j - i])){
                    result = std::to_string(vec[i]) + std::to_string(vec[j]) + std::to_string(vec[j + j - i]);
                    return result;
                }

            }
        }
    }
    return "-1";
}