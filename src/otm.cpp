#include "otm.h"

void generateTag(Ctxt& tagCtxt, ZZ& maskAdd, ZZ& maskMul, const Ctxt& hdCtxt){
    ZZX maskAddPoly, maskMulPoly;
    
    RandomBits(maskAdd, RANDOMBIT);
    RandomBits(maskMul, RANDOMBIT);

    ZZtoZZX(maskAddPoly, maskAdd);
    ZZtoZZX(maskMulPoly, maskMul);
    
    tagCtxt = hdCtxt;
    tagCtxt.multByConstant(maskMulPoly);
    tagCtxt.addConstant(maskAddPoly);
}

void recoverMsg(ZZX& recPoly, const ZZ& maskAdd, const ZZ& maskMul, const ZZX& tagPoly){
    ZZX maskAddPoly, maskMulPoly;

    ZZtoZZX(maskAddPoly, maskAdd);
    ZZtoZZX(maskMulPoly, maskMul);

    recPoly = tagPoly;
    recPoly -= maskAddPoly;
    div(recPoly, recPoly, maskMulPoly);
}

void recoverMsg(ZZ& recMsg, const ZZ& maskAdd, const ZZ& maskMul, const ZZX& tagPoly){
    recMsg = ZZXtoZZ(tagPoly);
    recMsg -= maskAdd;
    recMsg /= maskMul;
}