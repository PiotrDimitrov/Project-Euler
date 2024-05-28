/*
   The decimal number, 585 = 1001001001[2] (binary), is palindromic in both
   bases.

   Find the sum of all numbers, less than one million, which are palindromic
   in base 10 and base 2.

   (Please note that the palindromic number, in either base, may not include
   leading zeros.)
 */
#include <string>
namespace pr36{

    bool isPal(std::string s){
        for (int i = 0; i < s.length()/2; i++){
            if (s[i] != s[s.length()-1-i]) {return false;}
        }
        return true;
    }

    std::string toStr(int x){
        std::string str;
        int num = x;
        while (num > 0){
            str = char(num%10 + '0') + str;
            num /= 10;
        }
        return str;
    }

    std::string toBin(int x){
        
    }
}

int problem36() {
    int result = 0;
    for (int i = 1; i < 100000; i++){

    }
}