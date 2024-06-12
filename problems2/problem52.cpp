/*
   It can be seen that the number, 125874, and its double, 251748, contain
   exactly the same digits, but in a different order.

   Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x,
   contain the same digits.
 */
#include <vector>

namespace pr52 {
    std::vector<int> digitSet(int n){
        std::vector<int> vec(10, 0);
        while (n > 0){
            vec[n%10]++;
            n /= 10;
        }
        return vec;
    }

    bool sameDigits(int a, int b){
        return digitSet(a) == digitSet(b);
    }
}

int problem52() {
    for (int c = 1; c < 10000000; c++) {


        bool flag = true;
        for (int x = 1; x < 6; x++) {
            flag = flag && pr52::sameDigits(c*x, c*(x+1));
            if (!flag) {break;}
        }
        if (flag) {return c;}
    }
}