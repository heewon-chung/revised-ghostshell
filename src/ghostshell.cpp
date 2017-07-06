#include "ghostshell.h"

using namespace std;
using namespace NTL;

void enrollment(vector<Ctxt>& encIris, ZZ& rnd, const vector<long>& iris, const EncryptedArray& ea, const FHESecKey& secretKey){
    assert(iris.size() == NUMBITS);
    encIris.clear();
    encIris.resize(NUMBITS + 1, secretKey);
    
    vector<NewPlaintextArray> encodedIris(NUMBITS + 1, ea);

    enrollMsgEncode(encodedIris, iris, ea);
    
    for(unsigned long i = 0; i < encodedIris.size(); i++){
        ea.encrypt(encIris[i], secretKey, encodedIris[i]);
    }
}

void authnetication(vector<Ctxt>& encIris, const vector<long>& iris, const EncryptedArray& ea, const FHESecKey& secretKey){
    assert(iris.size() == NUMBITS);
    encIris.clear();
    encIris.resize(NUMBITS + 1, secretKey);
    vector<NewPlaintextArray> encodedIris(NUMBITS, ea);

    authMsgEncode(encodedIris, iris, ea);

    for(unsigned long i = 0; i < encodedIris.size(); i++){
        ea.encrypt(encIris[i], secretKey, encodedIris[i]);
    }
}

void verification(Ctxt& tagCtxt, ZZ& maskAdd, ZZ& maskMul, const vector<Ctxt>& encIris1, const vector<Ctxt>& encIris2){    
    hammingDistance(tagCtxt, encIris1, encIris2);
    generateTag(tagCtxt, maskAdd, maskMul, tagCtxt);
}

// void decryption(vector<long>& tagPtxt, vector<ZZ>& authGroup, const Ctxt& tagCtxt, const EncryptedArray& ea, const FHESecKey& secretKey){
//     ea.decrypt(tagCtxt, secretKey, tagPtxt);
// }