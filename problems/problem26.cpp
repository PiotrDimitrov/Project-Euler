/*
   A unit fraction contains 1 in the numerator. The decimal representation of
   the unit fractions with denominators 2 to 10 are given:

     1/2  = 0.5
     1/3  = 0.(3)
     1/4  = 0.25
     1/5  = 0.2
     1/6  = 0.1(6)
     1/7  = 0.(142857)
     1/8  = 0.125
     1/9  = 0.(1)
     1/10 = 0.1

   Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can
   be seen that 1/7 has a 6-digit recurring cycle.

   Find the value of d < 1000 for which ^1/[d] contains the longest recurring
   cycle in its decimal fraction part.
*/
#include <vector>

bool in(std::vector<int> v, int x){
    for (int e : v){
        if (x == e) {return true;}
    }
    return false;
}

int problem26() {
    std::vector<int> digits;

    int result = 0;
    int max = 0;
    for (int i = 2; i < 1000; i++) {
        digits.clear();
        int current = 1;
        int length = 0;
        while (true) {
            current = current % i;
            if (in(digits, current)){break;}
            digits.push_back(current);
            current *= 10;
            length++;
            if (current == 0) {
                length = 0;
                break;
            }
        }
        if (length > max) {max = length; result = i;}
    }
    return result;
}