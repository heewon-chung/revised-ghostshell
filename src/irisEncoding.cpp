#include "irisEncoding.h"

void enrollIrisEncode(vector<ZZX>& encodedIris, const vector<ZZX>& iris){
    assert(iris.size() == NUMBITS);
    encodedIris.clear();
    encodedIris.resize(NUMBITS + 1);
    
    #pragma omp parallel for
    for(unsigned long i = 0; i < NUMBITS; i++){
        if(IsOne(iris[i])){
            ZZtoZZX(encodedIris[i], MSGRND1);
        }
        else{
            ZZtoZZX(encodedIris[i], MSGRND2);
        }
    }
    
    ZZtoZZX(encodedIris[NUMBITS], MASKRND);
}


void authIrisEncode(vector<ZZX>& encodedIris, const vector<ZZX>& iris){
    assert(iris.size() == NUMBITS);
    
    encodedIris.clear();
    encodedIris.resize(NUMBITS + 1);

    #pragma omp parallel for
    for(unsigned long i = 0; i < NUMBITS; i++){
        if(IsOne(iris[i])){
            ZZtoZZX(encodedIris[i], MSGRND1);
        }
        else{
            ZZtoZZX(encodedIris[i], MSGRND2);
        }
    }
}