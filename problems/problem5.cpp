/*
   2520 is the smallest number that can be divided by each of the numbers
   from 1 to 10 without any remainder.

   What is the smallest positive number that is evenly divisible by all of
   the numbers from 1 to 20?
*/
#include <iostream>

int problem5() {
    int limit = 20;
    long long result = 1;
    int arr[limit];
    for (int i = 0; i < limit; i++) {
        arr[i] = 1+i;
    }
    for (int i = 1; i < limit; i++){
        if (arr[i] == 0) { continue;}
        for (int j = 2*arr[i]; j < limit; j += arr[i]){
            arr[j-1] = 0;
        }
    }
    for (auto e : arr){
        if (e < 2) { continue; }
        int i = 1;
        while (i*e < limit){
            i *= e;
        }
        result *= i;
    }
    return result;
}