/*
   Take the number 192 and multiply it by each of 1, 2, and 3:

     192 × 1 = 192
     192 × 2 = 384
     192 × 3 = 576

   By concatenating each product we get the 1 to 9 pandigital, 192384576. We
   will call 192384576 the concatenated product of 192 and (1,2,3)

   The same can be achieved by starting with 9 and multiplying by 1, 2, 3, 4,
   and 5, giving the pandigital, 918273645, which is the concatenated product
   of 9 and (1,2,3,4,5).

   What is the largest 1 to 9 pandigital 9-digit number that can be formed as
   the concatenated product of an integer with (1,2, ... , n) where n > 1?
 */
#include <vector>
#include <string>
#include <algorithm>

namespace pr38 {
    std::string pandigit(int x){
        std::string prod = "";
        for (int m = 1; m <= 9; m++){
            prod = prod + std::to_string(m*x);
            if (prod.length() >= 9){break;}
        }
        if (prod.length() != 9) {return "";}
        std::vector<int> vec(10, 0);

        for (char c : prod) {
            int digit = c - '0';
            if (digit == 0 || vec[digit] > 0) return "";
            vec[digit]++;
        }
        return prod;
    }
}

long problem38() {
    int result = 0;
    for (int i = 10000; i > 0; --i) {
        std::string temp = pr38::pandigit(i);
        if (!temp.empty()) {
            long prod = 0;
            prod = std::stol(temp);
            if (prod > result) {
                result = prod;
            }
        }
    }
    return result;
}
