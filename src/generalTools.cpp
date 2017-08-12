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
    long    coeff = 0;

    while(tmpMsg > 0){
        long rem = tmpMsg % POLYMODLUS;
        SetCoeff(encodedPoly, coeff, rem);
        coeff++;
        tmpMsg -= rem;
        tmpMsg /= POLYMODLUS;
    }
}

void ZZtoZZX(ZZX& encodedPoly, const int& msg){
    int     tmpMsg = msg;
    long    coeff = 0;

    while(tmpMsg > 0){
        long rem = tmpMsg % POLYMODLUS;
        SetCoeff(encodedPoly, coeff, rem);
        coeff++;
        tmpMsg -= rem;
        tmpMsg /= POLYMODLUS;
    }
}

ZZ ZZXtoZZ(const ZZX& poly){
    int degree = deg(poly);
    ZZ  multiplier = conv<ZZ>(POLYMODLUS);
    
    if(degree > 0){
        ZZ eval = poly[0];
        for(unsigned long i = 1; i < degree + 1; i++){
            eval += poly[i] * multiplier;
            multiplier *= POLYMODLUS;
        }
        return eval;
    }
    else if(degree == 0){
        return poly[0];
    }
    else{
        return conv<ZZ>(0);
    }   
}