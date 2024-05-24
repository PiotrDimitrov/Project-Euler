/*
   Starting with the number 1 and moving to the right in a clockwise
   direction a 5 by 5 spiral is formed as follows:

                                 21 22 23 24 25
                                 20  7  8  9 10
                                 19  6  1  2 11
                                 18  5  4  3 12
                                 17 16 15 14 13

   It can be verified that the sum of the numbers on the diagonals is 101.

   What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral
   formed in the same way?
 */

long long problem28() {
    long long result = 0;
    int step = 2;
    int counter = 0;
    for (long i = 1; i <= 1001*1001; i += step){
        result += i;
        if (counter == 4){
            step += 2;
            counter = 0;
        }
        counter++;

    }
    return result;
}