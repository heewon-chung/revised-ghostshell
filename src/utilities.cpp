#include "utilities.h"

// void multiplyAllPrimes(ZZ& prodPrime, const vector<long>& prime){
//     int size = prime.size();
//     assert(size > 0);

//     prodPrime = prime[0];
//     for(unsigned long i = 1; i < size; i++){
//         prodPrime *= prime[i];
//     }
// }

ZZ multiplyAllPrimes(const vector<long>& prime){
    int size = prime.size();
    assert(size > 0);

    ZZ prodPrime = conv<ZZ>(prime[0]);
    for(unsigned long i = 1; i < size; i++){
        prodPrime *= prime[i];
    }
}