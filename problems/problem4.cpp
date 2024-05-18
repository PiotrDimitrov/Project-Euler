/*
   A palindromic number reads the same both ways. The largest palindrome made
   from the product of two 2-digit numbers is 9009 = 91 × 99.

   Find the largest palindrome made from the product of two 3-digit numbers.
 */
#include <iostream>

namespace pr4 {
    bool isPal(int x){
        bool result;
        std::string str;
        while (x > 0){ str = char(x%10 + '0') + str; x /= 10; }
        int len = str.length();
        for (int i = 0; i < len; i++){
            if (str[i] != str[len - i - 1]) {return false;}
        }
        return true;
    }
}

int problem4() {
    long result;
    for (int i = 999; i > 100; i--){
        for (int j = 999; j > 100; j--){
            if (i*j > result && pr4::isPal(i*j)) {result = i*j;}
        }
    }
    return result;
}