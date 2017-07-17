#include "generalTools.h"


void ZZtoZZX(ZZX& encodedPoly, const ZZ& msg){
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

void ZZXtoZZ(ZZ& msg, const ZZX& poly){

}

void generateVectorInstance(vector<ZZX>& vecPoly){
    vecPoly.clear();
    vecPoly.resize(NUMBITS);
    
    for(unsigned long i = 0; i < NUMBITS; i++){
        if(rand() % 2){
            ZZtoZZX(vecPoly[i], MSGRND1);
        }
        else{
            ZZtoZZX(vecPoly[i], MSGRND1 + 1);
        }
    }
}