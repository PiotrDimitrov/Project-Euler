/*
    Euler discovered the remarkable quadratic formula:

                                  n² + n + 41

   It turns out that the formula will produce 40 primes for the consecutive
   values n = 0 to 39. However, when n = 40, 40^2 + 40 + 41 = 40(40 + 1) + 41
   is divisible by 41, and certainly when n = 41, 41² + 41 + 41 is clearly
   divisible by 41.

   The incredible formula n² − 79n + 1601 was discovered, which produces 80
   primes for the consecutive values n = 0 to 79. The product of the
   coefficients, −79 and 1601, is −126479.

   Considering quadratics of the form:

     n² + an + b, where |a| < 1000 and |b| < 1000

     where |n| is the modulus/absolute value of n
     e.g. |11| = 11 and |−4| = 4

   Find the product of the coefficients, a and b, for the quadratic
   expression that produces the maximum number of primes for consecutive
   values of n, starting with n = 0.
 */

bool isPrime(int x){
    if (x <= 1) {return false;}
    for (int i = 2; i * i <= x; i++){
        if (x % i == 0) {return false;}
    }
    return true;
}

int problem27() {
    int maxL = 0;
    int result;
    for (int a = -1000; a <= 1000; a++){
        for (int b = -1000; b <= 1000; b++){
            int c = 0;
            int length = 0;
            int current = c*c + a*c + b;
            while (isPrime(current)){
                length++;
                c++;
                current = c*c + a*c + b;
            }
            if (length > maxL) {maxL = length; result = a*b;}
        }
    }
    return result;
}