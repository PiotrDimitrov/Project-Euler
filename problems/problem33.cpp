/*
   The fraction 49/98 is a curious fraction, as an inexperienced
   mathematician in attempting to simplify it may incorrectly believe that
   49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

   We shall consider fractions like, 30/50 = 3/5, to be trivial
   examples.

   There are exactly four non-trivial examples of this type of fraction, less
   than one in value, and containing two digits in the numerator and
   denominator.

   If the product of these four fractions is given in its lowest common
   terms, find the value of the denominator.
 */
#include <iostream>
int problem33() {
    int num = 1, den = 1;
    for (int i = 11; i < 99; i++){
        for (int j = i+1; j <= 99; j++){
            if (i % 10 == j % 10 && i % 10 == 0){continue;}
            if (i % 10 == j % 10 && (i/10)*1.0/(j/10) == i*1.0/j) {num *= i/10; den *= j/10;}
            if (i % 10 == j / 10 && (i/10)*1.0/(j%10) == i*1.0/j) {num *= i/10; den *= j%10;}
            if (i / 10 == j % 10 && (i%10)*1.0/(j/10) == i*1.0/j) {num *= i%10; den *= j/10;}
            if (i / 10 == j / 10 && (i%10)*1.0/(j%10) == i*1.0/j) {num *= i%10; den *= j%10;}
        }
    }
    return den / num;
}
// 16/64
// 26/65
// 19/95
// 49/98