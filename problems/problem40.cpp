/*
   An irrational decimal fraction is created by concatenating the positive
   integers:

                     0.123456789101112131415161718192021...

   It can be seen that the 12^th digit of the fractional part is 1.

   If d[n] represents the n^th digit of the fractional part, find the value
   of the following expression.

      d[1] × d[10] × d[100] × d[1000] × d[10000] × d[100000] × d[1000000]
 */
#include <cmath>
#include <algorithm>
#include <string>

int problem40() {
    int current = 0;
    int digit = 0;
    int power = 0;
    int result = 1;
    while (digit <= 1000000){
        current++;
        std::string temp = std::to_string(current);
        for (char c : temp){
            digit++;
            if (digit == pow(10, power)){power++; result *= int(c - '0');}
        }
    }
    return result;
}