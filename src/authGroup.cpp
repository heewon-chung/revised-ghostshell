#include "authGroup.h"

void generateAuthGroup(long& generator, vector<ZZ>& authGroup){
    authGroup.clear();
    authGroup.resize(THRESHOLD);

    RandomBits(generator, GENERATORBIT);
    
    ZZ rnd = MASKRND * MASKRND;

    #pragma omp parallel for
    for(unsigned long i = 0; i < THRESHOLD; i++){
        long exponent = (rnd + i) % DLGROUPORDER;
        power(authGroup[i], generator, exponent);
    }
}

bool isInGroup(const ZZ& msgDL, const vector<ZZ>& authGroup){
    bool isValidity = false;
    long groupSize = authGroup.size();

    #pragma omp parallel for
    for(unsigned long i = 0; i < groupSize; i++){
        if(authGroup[i] == msgDL){
            isValidity = true;
            break;
        }
    }

    return isValidity;
}