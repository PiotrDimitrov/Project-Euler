/*
By starting at the top of the triangle below and moving to adjacent
   numbers on the row below, the maximum total from top to bottom is 23.

                                       3
                                      7 4
                                     2 4 6
                                    8 5 9 3

   That is, 3 + 7 + 4 + 9 = 23.

   Find the maximum total from top to bottom of the triangle below:

                                       75
                                     95 64
                                    17 47 82
                                  18 35 87 10
                                 20 04 82 47 65
                               19 01 23 75 03 34
                              88 02 77 73 07 63 67
                            99 65 04 28 06 16 70 92
                           41 41 26 56 83 40 80 70 33
                         41 48 72 33 47 32 37 16 94 29
                        53 71 44 65 25 43 91 52 97 51 14
                      70 11 33 28 77 73 17 78 39 68 17 57
                     91 71 52 38 17 14 91 43 58 50 27 29 48
                   63 66 04 68 89 53 67 30 73 16 69 87 40 31
                  04 62 98 27 23 09 70 98 73 93 38 53 60 04 23

   NOTE: As there are only 16384 routes, it is possible to solve this problem
   by trying every route. However, [1]Problem 67, is the same challenge with
   a triangle containing one-hundred rows; it cannot be solved by brute
   force, and requires a clever method! ;o)
*/
#include <fstream>
#include <iostream>

namespace pr18 {
    int toInt(std::string s, int i) {
        return (s[i]-'0')*10 + (s[i+1]-'0');
    }
}

int problem18() {
    int** triangle = new int*[15];
    for (int i = 0; i < 15; i++) {
        triangle[i] = new int[i+1];
    }

    std::fstream fs;
    fs.open("../files/problem18.txt", std::fstream::in);
    if (!fs.is_open()){
        std::cout << "Error opening file" << std::endl;
        return 1;
    }
    std::string msg;
    int i = 0; int j = 0;
    while(!fs.eof()) {
        fs >> msg;
        triangle[i][j] = pr18::toInt(msg, 0);
        msg = "";
        j++;
        if (j > i) {i++; j = 0;}
    }

    for (int i = 1; i < 15; i++){
        int j = 0;
        triangle[i][j] += triangle[i-1][j];
        for (j = 1; j < i; j++){
            triangle[i][j] += std::max(triangle[i-1][j-1], triangle[i-1][j]);
        }
        j = i;
        triangle[i][j] += triangle[i-1][j-1];
    }

    int result = triangle[14][0];
    for (int a = 0; a < 15; a++){
        if (result < triangle[14][a]) {result = triangle[14][a];}
    }

    for (int i = 0; i < 15; i++) {
        delete [] triangle[i];
    }
    delete [] triangle;

    return result;
}

