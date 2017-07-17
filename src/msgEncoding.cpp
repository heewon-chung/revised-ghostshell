#include "msgEncoding.h"

void enrollMsgEncode(vector<NewPlaintextArray>& encodedIris, const vector<long>& iris, const EncryptedArray& ea){
    assert(iris.size() == NUMBITS);
    assert(encodedIris.size() == NUMBITS + 1);
    
    vector<ZZX> encodedPoly;
    encodedPoly.resize(NUMBITS + 1);

    #pragma omp parallel for
    for(unsigned long i = 0; i < NUMBITS; i++){
        if(iris[i]){
            ZZtoZZX(encodedPoly[i], MSGRND1);
        }
        else{
            ZZtoZZX(encodedPoly[i], MSGRND1 + 1);
        }
        encode(ea, encodedIris[i], encodedPoly[i]);
    }

    ZZtoZZX(encodedPoly[NUMBITS], MASKRND);
    encode(ea, encodedIris[NUMBITS], encodedPoly[NUMBITS]);
}

void authMsgEncode(vector<NewPlaintextArray>& encodedIris, const vector<long>& iris, const EncryptedArray& ea){
    assert(iris.size() == NUMBITS);
    assert(encodedIris.size() == NUMBITS + 1);
    
    vector<ZZX> encodedPoly;
    encodedPoly.resize(NUMBITS + 1);

    #pragma omp parallel for
    for(unsigned long i = 0; i < NUMBITS; i++){
        if(iris[i]){
            ZZtoZZX(encodedPoly[i], MSGRND1);
        }
        else{
            ZZtoZZX(encodedPoly[i], MSGRND1 + 1);
        }
        encode(ea, encodedIris[i], encodedPoly[i]);
    }

    encode(ea, encodedIris[NUMBITS], encodedPoly[NUMBITS]);
}