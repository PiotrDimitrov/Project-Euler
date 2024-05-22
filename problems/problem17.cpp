/*
   If the numbers 1 to 5 are written out in words: one, two, three, four,
   five, then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.

   If all the numbers from 1 to 1000 (one thousand) inclusive were written
   out in words, how many letters would be used?

   NOTE: Do not count spaces or hyphens. For example, 342 (three hundred and
   forty-two) contains 23 letters and 115 (one hundred and fifteen) contains
   20 letters. The use of "and" when writing out numbers is in compliance
   with British usage.
*/
#include <vector>
#include <string>

int problem17() {
    int result = 0;
    std::vector <std::string> vec = {
            "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
            "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
            "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety",
            "hundred", "thousand"};

    //21 -> 30
    //22 -> 40
    //...
    //27 -> 90
    //28 -> 100
    //29 -> 1000

    for (int i = 1; i < 1000; i++) {
        if (i % 100 <= 20) {
            result += vec[i%100].length();
        }
        else {
            result += vec[i%10].length() + vec[(i%100)/10 -2 +20].length();
        }
        if (i > 99) {result += vec[28].length() + vec[i / 100].length();}
    }
    return result + vec[1].length() + vec[29].length();
} //21124