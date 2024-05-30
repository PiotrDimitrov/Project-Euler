/*
   The n^th term of the sequence of triangle numbers is given by, t[n] =
   n(n+1)/2; so the first ten triangle numbers are:

                    1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

   By converting each letter in a word to a number corresponding to its
   alphabetical position and adding these values we form a word value. For
   example, the word value for SKY is 19 + 11 + 25 = 55 = t[10]. If the word
   value is a triangle number then we shall call the word a triangle word.

   Using [1]words.txt, a 16K text file containing nearly two-thousand common
   English words, how many are triangle words?
 */
#include <fstream>

namespace pr42 {
    bool isTri(int x){
        int step = 1;
        while (x > 0){
            x -= step;
            step++;
        }
        if (x == 0) {return true;}
        return  false;
    }
}

int problem42 () {
    std::fstream fs;
    int result = 0;
    fs.open("../files/problem42.txt", std::fstream::in);
    if (!fs.is_open()){
        return -1;
    }
    std::string msg;
    while(!fs.eof()){
        fs >> msg;
        int current = -1;
        bool flag = false;
        for (char c : msg){
            if (c == '\"' && flag){
                if (pr42::isTri(current)) {result++;}
                flag = false;
                continue;}
            if (c == '\"' && flag == false){
                current = 0;
                flag = true;
                continue;
            }
            if (!flag) {continue;}
            current += int(c - 'A' + 1);
        }
        msg = "";
    }
    return result;
}