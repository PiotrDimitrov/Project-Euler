/*
   The prime factors of 13195 are 5, 7, 13 and 29.

   What is the largest prime factor of the number 600851475143 ?
*/

int problem3() {
    int long long n = 600851475143;
    int result;
    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {n /= i; result = i; i = 2;}
    }
    return result;
}