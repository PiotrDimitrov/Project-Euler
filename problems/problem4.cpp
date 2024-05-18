/*
   A palindromic number reads the same both ways. The largest palindrome made
   from the product of two 2-digit numbers is 9009 = 91 × 99.

   Find the largest palindrome made from the product of two 3-digit numbers.
 */
#include <iostream>

namespace pr4 {
    bool isPal(long x){
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
    for (int i = 999*2; i > 0; i--) {
        int n1 = i / 2;
        int n2 = i - n1;
        while (n2 <= 999) {
            if (pr4::isPal(n1*n2)) { return n1*n2;}
            --n1; ++n2;
        }
    }
    return 0;
}

//int problem4() {
//    long result;
//    for (int i = 999; i > 100; i--){
//        for (int j = 999; j >= i; j--){
//            if (i*j > result && pr4::isPal(i*j)) {result = i*j;}
//        }
//    }
//    return result;
//}

