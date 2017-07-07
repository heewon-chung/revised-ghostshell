#include "otm.h"

void generateTag(Ctxt& tagCtxt, ZZ& maskAdd, ZZ& maskMul, const Ctxt& hdCtxt){
    ZZX     maskAddPoly, maskMulPoly;

    RandomBits(maskAdd, RANDOMBIT);
    RandomBits(maskMul, RANDOMBIT);

    integerToZZX(maskAddPoly, maskAdd);
    integerToZZX(maskMulPoly, maskMul);

    tagCtxt = hdCtxt;
    tagCtxt.multByConstant(maskMulPoly);
    tagCtxt.addConstant(maskAddPoly);
}

void generateAuthGroup(long& generator, vector<ZZ>& authGroup){
    authGroup.clear();
    authGroup.resize(THRESHOLD);

    RandomBits(generator, GENERATORBIT);
    
    ZZ rnd = MASKRND;
    power(rnd, rnd, 2);

    #pragma omp parallel for
    for(unsigned long i = 0; i < THRESHOLD; i++){
        long exponent = (rnd + i) % DLGROUPORDER;
        power(authGroup[i], generator, exponent);
    }
}