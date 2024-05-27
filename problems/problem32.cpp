/*
   We shall say that an n-digit number is pandigital if it makes use of all
   the digits 1 to n exactly once; for example, the 5-digit number, 15234, is
   1 through 5 pandigital.

   The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing
   multiplicand, multiplier, and product is 1 through 9 pandigital.

   Find the sum of all products whose multiplicand/multiplier/product
   identity can be written as a 1 through 9 pandigital.

   HINT: Some products can be obtained in more than one way so be sure to
   only include it once in your sum.
 */
#include <iostream>
#include <vector>

namespace pr32{
    bool check(int a, int b){
        int arr[10];
        for (int i = 0; i < 10; i++){arr[i] = 0;}
        int prod = a * b;

        while (a > 0){
            arr[a%10]++;
            a /= 10;
        }
        while (b > 0){
            arr[b%10]++;
            b /= 10;
        }
        while (prod > 0){
            arr[prod%10]++;
            prod /= 10;
        }
        if (arr[0] != 0) {return false;}
        for (int k = 1; k < 10; k++){
            if (arr[k] != 1){return false;}
        }
        return true;
    }

    bool isIn(const std::vector<int> v, int x){
        for (auto e : v){
            if (x == e){return true;}
        }
        return false;
    }
}

int problem32() {
    std::vector<int> products;
    int result = 0;
    for (int i = 99; i <= 9999; i++){
        int cap = 99;
        if (i > 1000){cap = 10;}
        for (int j = 0; j <= cap; j++){
            if (pr32::check(i ,j)){
                if (!pr32::isIn(products, i*j)){products.push_back(i*j);}
            }
        }
    }
    for (auto e : products){
        result += e;
    }
    return result;
}