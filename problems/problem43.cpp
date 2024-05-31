/*
   The number, 1406357289, is a 0 to 9 pandigital number because it is made
   up of each of the digits 0 to 9 in some order, but it also has a rather
   interesting sub-string divisibility property.

   Let d[1] be the 1^st digit, d[2] be the 2^nd digit, and so on. In this
   way, we note the following:

     •d[2]d[3]d[4]=406 is divisible by 2
     •d[3]d[4]d[5]=063 is divisible by 3
     •d[4]d[5]d[6]=635 is divisible by 5
     •d[5]d[6]d[7]=357 is divisible by 7
     •d[6]d[7]d[8]=572 is divisible by 11
     •d[7]d[8]d[9]=728 is divisible by 13
     •d[8]d[9]d[10]=289 is divisible by 17

   Find the sum of all 0 to 9 pandigital numbers with this property.
 */
#include <vector>
#include <iostream>
#include "../libs/bigNum.h"

namespace pr43 {
    void swap(std::vector<int>& v, int i, int j){
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }

    bool nextPemr(std::vector<int>& v){
        int n = v.size();
        int j = n - 2;
        while (v[j] >= v[j+1] && j >= 0){
            j--;
        }
        if (j < 0){return false;}
        int k = n - 1;
        while (v[k] <= v[j]){
            k--;
        }
        swap(v, j, k);
        int l = j + 1;  int r = n - 1;
        while (r > l){
            swap(v, r, l);
            r--; l++;
        }
        return true;
    }

    void print (std::vector<int> v){
        for (int e : v){
            std::cout << e;
        }
        std::cout << std::endl;
    }

    bool check(std::vector<int> vec){
        int current = 1;
        int primes[7] = {2, 3, 5, 7,11, 13, 17};
        for (int i = 1; i <= 7; i++){
            current = vec[i]*100+vec[i+1]*10+vec[i+2];
            if (current % primes[i-1] != 0) {return false;}
        }
        return true;
    }

    bigNum toNum(std::vector<int> v){
        bigNum result;
        result.clear();
        for (int i = 9; i >= 0; i--){
           result.digits.push_back(v[i]);
        }
        return result;
    }
}

std::string problem43 () {
    bigNum result = 0;
    std::vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    while (pr43::nextPemr(nums)){
        if (pr43::check(nums)){result = result + pr43::toNum(nums);}
    }
    return result.toStr();
    //16695334890
}