/*
   The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

   Find the sum of all the primes below two million.
*/

long long problem10(){
    int cap = 2000001;
    bool arr[cap];
    for (int i = 0; i < cap; i++){
        arr[i] = true;
    }
    for (int i = 2; i*i <= cap; i++){
        if (arr[i]) {
            for (int j = i*i; j < cap; j+=i){
                arr[j] = false;
            }
        }
    }
    long long sum = 0;
    for (int i = 2; i < cap; i++){
        if(arr[i]){sum += i;}
    }
    return sum;
}//142913828922
