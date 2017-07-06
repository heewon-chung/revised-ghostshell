#include "match.h"

long hammingDistance(const vector<ZZX>& vec1Poly, const vector<ZZX>& vec2Poly){
    assert(vec1Poly.size() == vec2Poly.size());
    unsigned long numBits = vec1Poly.size();

    long hammingDistance = 0;

    for(unsigned long i = 0; i < numBits; i++){
        if(vec1Poly[i] != vec2Poly[i]){
            hammingDistance++;
        }
    }

    return hammingDistance;
}


void hammingDistance(Ctxt& hdCtxt, const vector<Ctxt>& vec1, const vector<Ctxt>& vec2){
    assert(vec1.size() == vec2.size());
    unsigned long numBits = vec1.size();

    hdCtxt = vec1[0];
    hdCtxt -= vec2[0];
    hdCtxt.square();

    #pragma omp parallel for
    for(unsigned long i = 1; i < numBits; i++){
        Ctxt tmp = vec1[i];
        tmp -= vec2[i];
        tmp.square();
        hdCtxt += tmp;
    }
}