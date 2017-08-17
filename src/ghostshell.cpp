#include "ghostshell.h"

void enrollment(vector<Ctxt>& encIris, const vector<ZZX>& iris, const FHESecKey& secretKey){
    assert(iris.size() == NUMBITS);
    assert(encIris.size() == NUMBITS + 1);
    
    // iris encoding for enrollment
    vector<ZZX> encodedIris;
    enrollIrisEncode(encodedIris, iris);
    assert(encodedIris.size() == NUMBITS + 1);
    
    // encryption encoding iris
    #pragma omp parallel for
    for(unsigned long i = 0; i < NUMBITS + 1; i++){
        secretKey.Encrypt(encIris[i], encodedIris[i]);
    }
}

void requestAuthenticate(vector<Ctxt>& encIris, const vector<ZZX>& iris, const FHESecKey& secretKey){
    assert(iris.size() == NUMBITS);
    assert(encIris.size() == NUMBITS + 1);
    
    // iris encoding for authentication
    vector<ZZX> encodedIris;
    authIrisEncode(encodedIris, iris);
    assert(encodedIris.size() == NUMBITS + 1);
    
    // encryption encoding iris
    #pragma omp parallel for
    for(unsigned long i = 0; i < NUMBITS + 1; i++){
        secretKey.Encrypt(encIris[i], encodedIris[i]);
    }
}

void computeHDandOTM(Ctxt& tagCtxt, ZZ& maskAdd, ZZ& maskMul, const vector<Ctxt>& encIris1, const vector<Ctxt>& encIris2){    
    hammingDistance(tagCtxt, encIris1, encIris2);
    generateTag(tagCtxt, maskAdd, maskMul, tagCtxt);
}

void decryptAndGenerateAuthGroup(long& generator, vector<ZZ>& authGroup, ZZ& tagDL, const Ctxt& tagCtxt, const FHESecKey& secretKey){
    ZZX tagPoly;
    secretKey.Decrypt(tagPoly, tagCtxt);
    ZZ tag = ZZXtoZZ(tagPoly);
    // long tagExponent = tag % DLGROUPORDER; 
    // power(tagDL, generator, tagExponent); 
    
    generateAuthGroup(generator, authGroup);
}

bool isValidity(const ZZ& tagDL, const long& generator, const vector<ZZ>& authGroup, const ZZ& maskAdd, const ZZ& maskMul){
    ZZ msgDL;
    recoverMsg(msgDL, tagDL, generator, maskAdd, maskMul);

    return isInGroup(msgDL, authGroup);
}