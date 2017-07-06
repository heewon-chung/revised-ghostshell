#include "generalTools.h"


void integerToZZX(ZZX& encodedPoly, const ZZ& msg){
    ZZ      tmpMsg = msg;
    long    amt = 0;

    while(tmpMsg > 0){
        long rem = tmpMsg % PRIMEFIELD;
        SetCoeff(encodedPoly, amt, rem);
        amt++;
        tmpMsg -= rem;
        tmpMsg /= PRIMEFIELD;
    }
}

void generateVectorInstance(vector<ZZX>& vecPoly){
    vecPoly.clear();
    vecPoly.resize(NUMBITS);
    
    for(unsigned long i = 0; i < NUMBITS; i++){
        if(rand() % 2){
            integerToZZX(vecPoly[i], MSGRND1);
        }
        else{
            integerToZZX(vecPoly[i], MSGRND1 + 1);
        }
    }
}