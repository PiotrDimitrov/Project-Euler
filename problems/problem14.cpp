/*
   The following iterative sequence is defined for the set of positive
   integers:

   n → n/2 (n is even)
   n → 3n + 1 (n is odd)

   Using the rule above and starting with 13, we generate the following
   sequence:

                   13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1

   It can be seen that this sequence (starting at 13 and finishing at 1)
   contains 10 terms. Although it has not been proved yet (Collatz Problem),
   it is thought that all starting numbers finish at 1.

   Which starting number, under one million, produces the longest chain?

   NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <iostream>

int problem14() {
    int cap = 1000000;
    int result = 0;
    int* arr = new int[cap];
    for (int i = 0; i < cap; i++){
        arr[i]  = i+1;
    }
    int max = 0;
    for (int i = 0; i < cap; i++) {
        if (arr[i] == 0) {
            continue;
        }
        long long current = arr[i];
        int count = 0;

        while (current > 1) {
            if (current % 2 == 0) {current /= 2;}
            else {current = current * 3 + 1;}
            count++;
            if (current < cap) {arr[current] = 0;}
        }
        if (count > max) {max = count; result = i+1;}
    }
    delete [] arr;
    return result;
}