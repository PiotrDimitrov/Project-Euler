/*
   Surprisingly there are only three numbers that can be written as the sum
   of fourth powers of their digits:

     1634 = 1^4 + 6^4 + 3^4 + 4^4
     8208 = 8^4 + 2^4 + 0^4 + 8^4
     9474 = 9^4 + 4^4 + 7^4 + 4^4

   As 1 = 1^4 is not a sum it is not included.

   The sum of these numbers is 1634 + 8208 + 9474 = 19316.

   Find the sum of all the numbers that can be written as the sum of fifth
   powers of their digits.
 */
#include <cmath>
#include <iostream>
namespace pr30{
    int sumOfFifs(int x) {
        int result = 0;
        while (x > 0) {
            result += pow(x%10, 5);
            x /= 10;
        }
        return result;
    }
}

long problem30(){
    int result = 0;
    for (int i = 2; i < 200000; i++){
        if (i == pr30::sumOfFifs(i)) {result += i;}
//        std::cout << i << " : " << i - pr30::sumOfFifs(i) << std::endl;
    }
    return result;
} //443839