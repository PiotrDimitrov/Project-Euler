/*
   A Pythagorean triplet is a set of three natural numbers, a < b < c, for
   which,

                                a^2 + b^2 = c^2

   For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

   There exists exactly one Pythagorean triplet for which a + b + c = 1000.
   Find the product abc.
*/

#include <iostream>

//use Euclid's algorithm to generate Pythagorean triplets
// a = m^2 - n^2, b = 2mn, c = m^2 + n^2, where m < n < 0, m and n - integers
// a + b + c = 1000
//using simple algebraic transformations we get:
// 2m^2 + 2mn = 1000
// thus: 500/m - m = n
//program will look for integer m which will have two properties
// 500 % m == 0 and 500/m - m > 0

int problem9() {
    int sum = 1000;

    int m, n;
    sum /= 2;
    for (m = sum; m > 0; m--) {
        if ((sum) % m == 0 and sum/m - m > 0) {break;}
    }
    n = sum/m - m;
    int a = m*m - n*n, b = 2*m*n, c = m*m + n*n;

    return a*b*c;
}


