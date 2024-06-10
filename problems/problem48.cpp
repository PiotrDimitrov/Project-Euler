/*
   The series, 1^1 + 2^2 + 3^3 + ... + 10^10 = 10405071317.

   Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000.
 */
#include "../libs/bigNum.h"
#include <cmath>
#include <iostream>

long long problem48() {
    bigNum result;
    int index = 0;
//    for (bigNum i("1"); i <= "1000"; i = i + "1"){
//        index++;
//        bigNum temp("1");
//        int count = 0;
//        while (temp.digits.size() <= 10 && count <= index){
//            temp = temp * i;
//            count++;
//        }
//        result = result + temp;
//
//    }
for (int i = 1; i <= 1000; i++){
    bigNum temp(i);
    bigNum temp2 = temp ^ temp;
    result = result + temp2;
}
    long long res = 0;
    for (int i = 0; i < 10; i++){
        res += result.digits[i] * pow(10, i);
    }
    return res;
}