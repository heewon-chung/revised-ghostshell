#include "generalTools.h"

void generateVectorInstance(vector<vector<long>>& vec, const long numBits, const long numSlots){
    vec.clear();
    vec.resize(numBits);

    for(unsigned long i = 0; i < numBits; i++){
        vec[i].resize(numSlots, rand() % 2 + 1);
    }
}