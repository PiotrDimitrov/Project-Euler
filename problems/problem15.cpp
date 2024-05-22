/*
   Starting in the top left corner of a 2×2 grid, and only being able to move
   to the right and down, there are exactly 6 routes to the bottom right
   corner.

   How many such routes are there through a 20×20 grid?
*/
#include "../libs/bigNum.h"
#include <string>

namespace pr15{
    bigNum factorial(int x) {
        if (x <= 1) {return 1;}
        bigNum result(1);
        for (int i = 2; i <= x; i++) {
            result = result * i;
        }
        return result;
    }
}

//number of combinations
//result = 40!/(20!20!);

std::string problem15() {
    int grid = 20;
//    bigNum temp = pr15::factorial(grid);
//    bigNum result = pr15::factorial(2*grid) / (temp * temp);
    bigNum result = pr15::factorial(2*grid) / (pr15::factorial(grid)*pr15::factorial(grid));
    return result.toStr();
}
