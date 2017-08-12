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

void hammingDistance(Ctxt& hdCtxt, const vector<Ctxt>& ct1, const vector<Ctxt>& ct2){
    assert(ct1.size() == ct2.size());
    unsigned long ctxtSize = ct1.size();

    hdCtxt = ct1[0];
    hdCtxt -= ct2[0];
    hdCtxt.square();

    #pragma omp parallel for
    for(unsigned long i = 1; i < ctxtSize; i++){
        Ctxt tmpCtxt = ct1[i];
        tmpCtxt -= ct2[i];
        tmpCtxt.square();
        hdCtxt.addCtxt(tmpCtxt);
    }
}