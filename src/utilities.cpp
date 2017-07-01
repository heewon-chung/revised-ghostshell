#include "utilities.h"

// void multiplyAllPrimes(ZZ& prodPrime, const vector<long>& prime){
//     int size = prime.size();
//     assert(size > 0);

//     prodPrime = prime[0];
//     for(unsigned long i = 1; i < size; i++){
//         prodPrime *= prime[i];
//     }
// }

// ZZ multiplyAllPrimes(const vector<long>& prime){
//     int size = prime.size();
//     assert(size > 0);

//     ZZ prodPrime = conv<ZZ>(prime[0]);
//     for(unsigned long i = 1; i < size; i++){
//         prodPrime *= prime[i];
//     }

//     return prodPrime;
// }

void generateVectorInstance(vector<vector<long>>& vec, const long numBits, const long numSlots){
    vec.clear();
    vec.resize(numBits);

    for(unsigned long i = 0; i < numBits; i++){
        vec[i].resize(numSlots, rand() % 2 + 1);
    }
}

long printAndComputeHD(const vector<vector<long>>& vec1, const vector<vector<long>>& vec2){
    assert(vec1.size() == vec2.size());
    assert(vec1[0].size() == vec2[0].size());
    unsigned long numBits = vec1.size();
    unsigned long numSlots = vec1[0].size();

    long hammingDistance = 0;

    for(unsigned long i = 0; i < numBits; i++){
        // For all j and k, vec1[i][j] = vec1[i][k]
        if(vec1[i][0] != vec2[i][0]){
            hammingDistance++;
        }
    }

    cout << "\nHamming Distance = " << hammingDistance << endl;

    return hammingDistance;
}