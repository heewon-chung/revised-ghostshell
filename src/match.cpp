#include "match.h"

void hammingDistance(Ctxt& hdCtxt, const vector<Ctxt>& iris1, const vector<Ctxt>& iris2){
    assert(iris1.size() == iris2.size());
    unsigned long numBits = iris1.size();

    hdCtxt = iris1[0];
    hdCtxt -= iris2[0];
    hdCtxt.square();

    #pragma omp parallel for
    for(unsigned long i = 1; i < numBits; i++){
        Ctxt tmp = iris1[i];
        tmp -= iris2[i];
        tmp.square();
        hdCtxt += tmp;
    }
}