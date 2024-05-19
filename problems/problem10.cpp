/*
   The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

   Find the sum of all the primes below two million.
*/
#include <iostream>

long long problem10(){
    int cap = 2000000;
    int arr[cap];
    for (int i = 0; i < cap; i++){
        arr[i] = i+1;
    }

    for (int i = 1; i*i < cap; i++){
        if (arr[i] == 0) { continue;}
        for (int j = 2*i+1; j < cap; j += (i+1)){
            arr[j] = 0;
        }
    }

    for (auto i : arr){
        std::cout << i << " ";
    }
    return 0;
}
