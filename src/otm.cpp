#include "otm.h"

void generateTag(Ctxt& tagCtxt, ZZX& maskAddPoly, ZZX& maskMulPoly, const Ctxt& hdCtxt, const EncryptedArray& ea){
    NewPlaintextArray maskAdd(ea);
    NewPlaintextArray maskMul(ea);

    random(ea, maskAdd);
    random(ea, maskMul);

    ea.encode(maskAddPoly, maskAdd);
    ea.encode(maskMulPoly, maskMul);

    tagCtxt = hdCtxt;
    tagCtxt.multByConstant(maskMulPoly);
    tagCtxt.addConstant(maskAddPoly);
}

void recoverMsg(){

}

void generateAuthGroup(vector<ZZ>& authGroup, const long& generator, const long& groupOrder, const long& threshold, const ZZX& maskRnd){
    authGroup.clear();
    authGroup.resize(threshold);
    ZZ rnd = ConstTerm(maskRnd);
    power(rnd, rnd, 2);

    #pragma omp parallel for
    for(unsigned long i = 0; i < threshold; i++){
        ZZ tmp;
        AddMod(tmp, rnd, i, groupOrder);
        power(authGroup[i], generator, tmp);
    }
}