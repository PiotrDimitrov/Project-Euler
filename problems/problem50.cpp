/*
   The prime 41, can be written as the sum of six consecutive primes:

                          41 = 2 + 3 + 5 + 7 + 11 + 13

   This is the longest sum of consecutive primes that adds to a prime below
   one-hundred.

   The longest sum of consecutive primes below one-thousand that adds to a
   prime, contains 21 terms, and is equal to 953.

   Which prime, below one-million, can be written as the sum of the most
   consecutive primes?
 */
#include <vector>

int problem50() {
    std::vector<int> vec;
    vec.reserve(1000000);
    for (int i = 0; i < vec.capacity(); i++){
        vec.push_back(i);
    }
    for (int i = 2; i * i <= vec.size(); i++){
        if (vec[i] == 0){continue;}
        for (int j = vec[i]*vec[i]; j < vec.size(); j+=vec[i]){
            vec[j] = 0;
        }
    }

}