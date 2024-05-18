/*
   If we list all the natural numbers below 10 that are multiples of 3 or 5,
   we get 3, 5, 6 and 9. The sum of these multiples is 23.

   Find the sum of all the multiples of 3 or 5 below 1000.
 */

int problem1() {
    int cap = 1000;
    int result = 0;
    for (int i = 0; i < cap; i++) {
        if (i % 3 == 0) {result += i;
            continue;} //use continue to avoid adding numbers like 15, 30, 45 to result twice
        if (i % 5 == 0) {result += i;}
    }
    return result;
}
