/*
   A permutation is an ordered arrangement of objects. For example, 3124 is
   one possible permutation of the digits 1, 2, 3 and 4. If all of the
   permutations are listed numerically or alphabetically, we call it
   lexicographic order. The lexicographic permutations of 0, 1 and 2 are:

                         012  021  102  120  201  210

   What is the millionth lexicographic permutation of the digits 0, 1, 2, 3,
   4, 5, 6, 7, 8 and 9?
*/
#include <iostream>
#include <vector>

//long factorial(int x){
//    if (x <= 1) {return 1;}
//    return x * factorial(x - 1);
//}

void removeDigit(char c, std::string& str) {
    std::string temp;
    for (char e : str){
        if (e == c) { continue;}
        temp = temp + e;
    }
    str = temp;
}

std::string problem24 () {
    int position = 1000000;
    std::vector <int> vec;
    vec.reserve(9);
    int temp = 1;
    for (int i = 1; i <= 9; i++) {
        temp *= i;
        vec.push_back(temp);
    }
    int current = 1;
    std::string result = "";
    std::string digits = "0123456789";
    for (int i = 8; i >= 0; i--){
        int pivot = 0;
        while (current < position){
            pivot++;
            current += vec[i];
        }
        if (position > 1){
            if (i != 0 && current != position){
                pivot--;
                //pivot = pivot % digits.length();
            }
            result = result + digits[pivot];
            removeDigit(digits[pivot], digits);
            current -= vec[i];
        }
    }
    return result + digits;
}