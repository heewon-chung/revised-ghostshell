#include "msgEncoding.h"

void msgEncode(vector<ZZX>& encodedPoly, const vector<long>& iris){
    assert(iris.size() == NUMBITS);
    encodedPoly.clear();
    encodedPoly.resize(NUMBITS + 1);

    for(unsigned long i = 0; i < NUMBITS; i++){
        if(iris[i]){
            integerToZZX(encodedPoly[i], MSGRND1);
        }
        else{
            integerToZZX(encodedPoly[i], MSGRND1 + 1);
        }
    }
    ZZ rnd;
    RandomBits(rnd, RANDOMBIT);
    integerToZZX(encodedPoly[NUMBITS], rnd);
}