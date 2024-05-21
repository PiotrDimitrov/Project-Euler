#include <iostream>
#include "header.h"

int divisors(int n){
    int result = 0;
    int i;
    for (i = 1; i*i <= n; i++){
        if (n % i == 0) {result+=2;}
    }
    --i;
    if (i*i == n) {result = result - 1;}
    return result;
}

int main() {
    std::cout << problem12() << std::endl;
    return 0;
}
