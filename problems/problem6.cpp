/*
   The sum of the squares of the first ten natural numbers is,

                          1^2 + 2^2 + ... + 10^2 = 385

   The square of the sum of the first ten natural numbers is,

                       (1 + 2 + ... + 10)^2 = 55^2 = 3025

   Hence the difference between the sum of the squares of the first ten
   natural numbers and the square of the sum is 3025 − 385 = 2640.

   Find the difference between the sum of the squares of the first one
   hundred natural numbers and the square of the sum.
 */

int problem6 () {
    int x = 100;
    int sum1 = 0;
    int sum2 = 0;
    for (int i = 1; i <= x; i++){
        sum1 += i;
        sum2 += i*i;
    }
    sum1 *= sum1;
    return sum1 - sum2;
}