#include "generalTools.h"

void generateVectorInstance(vector<ZZX>& vecInst){
    vecInst.clear();
    
    for(unsigned long i = 0; i < NUMBITS; i++){
        vecInst.push_back(conv<ZZX>(rand() % 2));
    }
    
    assert(vecInst.size() == NUMBITS);
}

void generateVectorInstance(vector<vector<ZZX>>& vecInst, const EncryptedArray& ea){
    vecInst.clear();
    vecInst.resize(NUMBITS);

    for(unsigned long i = 0; i < NUMBITS; i++){
        ZZX msgPoly;
        ZZtoZZX(msgPoly, rand() % 2);
        ea.decode(vecInst[i], msgPoly);
    }
}

void ZZtoZZX(ZZX& encodedPoly, const ZZ& msg){
    ZZ      tmpMsg = msg;
    long    amt = 0;

    while(tmpMsg > 0){
        long rem = tmpMsg % 2;
        SetCoeff(encodedPoly, amt, rem);
        amt++;
        tmpMsg -= rem;
        tmpMsg /= PRIMEFIELD;
    }
}

void ZZtoZZX(ZZX& encodedPoly, const int& msg){
    int     tmpMsg = msg;
    long    amt = 0;

    while(tmpMsg > 0){
        long rem = tmpMsg % 2;
        SetCoeff(encodedPoly, amt, rem);
        amt++;
        tmpMsg -= rem;
        tmpMsg /= PRIMEFIELD;
    }
}