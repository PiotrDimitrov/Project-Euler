/*
   Using [1]names.txt, a 46K text file containing over five-thousand first
   names, begin by sorting it into alphabetical order. Then working out the
   alphabetical value for each name, multiply this value by its alphabetical
   position in the list to obtain a name score.

   For example, when the list is sorted into alphabetical order, COLIN, which
   is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So,
   COLIN would obtain a score of 938 × 53 = 49714.

   What is the total of all the name scores in the file?
*/
#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

std::string getName(std::string s, int i) {
    int index = i + 1;
    std::string result;
    while (s[index] != '\"') {
        result = result + s[index];
        i++;
    }
    return result;
}

int nameValue(std::string s) {
    int result = 0;
    for (int i = 0; i < s.length(); i++) {
        result += int(s[i] - 'A' + 1);
    }
    return result;
}

long long problem22 () {
    std::vector <std::string> names;
    int result = 0;
    std::fstream fs;
    fs.open("../files/problem22.txt", std::fstream::in);
    if (!fs.is_open()){
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    std::string msg;
    while (!fs.eof()){
        fs >> msg;
        int count = 0;
        std::string temp;
        for (int i = 0; i < msg.length(); i++) {
            if (msg[i] == '\"' && count == 0) {count++; continue;}
            if (msg[i] == '\"' && count == 1) {
                count--;
                names.push_back(temp);
                temp = "";
                continue;}
            if (count == 1) {temp = temp + msg[i];}
        }
    }
    std::sort(names.begin(), names.end());
    int pos = 1;
    for (auto e : names) {
        result += nameValue(e)*pos;
        pos++;
    }
    return result;
}