/*
   In England the currency is made up of pound, £, and pence, p, and there
   are eight coins in general circulation:

     1p, 2p, 5p, 10p, 20p, 50p, £1 (100p) and £2 (200p).

   It is possible to make £2 in the following way:

     1×£1 + 1×50p + 2×20p + 1×5p + 1×2p + 3×1p

   How many different ways can £2 be made using any number of coins?
 */
#include <vector>

int problem31() {
    std::vector<int> k = {1,2,4,10,20,40,100,200};
    const std::vector<int> m = {200,100,50,20,10,5,2,1};
    int result = 0;
    // a*200 + b*100 + c*50 + d*20 + e*10 + f*5 + g*2 + i*1
    int current;
    for (int a = k[0]; a >= 0; --a){
        for (int b = k[1]; b >= 0; --b){
            for (int c = k[2]; c >= 0; --c){
                for (int d = k[3]; d >= 0; --d){
                    for (int e = k[4]; e >= 0; --e){
                        for (int f = k[5]; f >= 0; --f){
                            for (int g = k[6]; g >= 0; --g){
                                current = a*m[0] + b*m[1] + c*m[2] + d*m[3] + e*m[4] + f*m[5] + g*m[6];
                                if (current <= k[7]){result++;}
                            }
                        }
                    }
                }
            }
        }
    }
    return result;
}