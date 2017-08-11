#include "match.h"

long hammingDistance(const vector<ZZX>& msg1, const vector<ZZX>& msg2){
    assert(msg1.size() == msg2.size());
    
    unsigned long   numBits = msg1.size(),
                    hammingDistance = 0;

    for(unsigned long i = 0; i < numBits; i++){
        if(msg1[i] != msg2[i]){
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
        Ctxt tmpCtxt = vec1[i];
        tmpCtxt -= vec2[i];
        tmpCtxt.square();
        hdCtxt.addCtxt(tmpCtxt);
    }
}