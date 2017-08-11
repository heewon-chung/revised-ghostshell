#include "ghostshell.h"

using namespace std;
using namespace NTL;

void enrollment(vector<Ctxt>& encIris, const vector<ZZX>& iris, const FHESecKey& secretKey){
    assert(iris.size() == NUMBITS);
    vector<ZZX> encodedIris;
    enrollIrisEncode(encodedIris, iris);
    assert(encodedIris.size() == NUMBITS + 1);
    #pragma omp parallel for
    for(unsigned long i = 0; i < NUMBITS + 1; i++){
        secretKey.Encrypt(encIris[i], encodedIris[i]);
    }
}

void authentication(vector<Ctxt>& encIris, const vector<ZZX>& iris, const FHESecKey& secretKey){
    assert(iris.size() == NUMBITS);
    vector<ZZX> encodedIris;
    authIrisEncode(encodedIris, iris);
    assert(encodedIris.size() == NUMBITS + 1);
    #pragma omp parallel for
    for(unsigned long i = 0; i < NUMBITS + 1; i++){
        secretKey.Encrypt(encIris[i], encodedIris[i]);
    }
}

void computeHDandOTM(Ctxt& tagCtxt, ZZ& maskAdd, ZZ& maskMul, const vector<Ctxt>& encIris1, const vector<Ctxt>& encIris2){    
    hammingDistance(tagCtxt, encIris1, encIris2);
    generateTag(tagCtxt, maskAdd, maskMul, tagCtxt);
}

// void decryptAndGenerateAuthGroup(ZZ& tagDL, long& generator, vector<ZZ>& authGroup, const Ctxt& tagCtxt, const EncryptedArray& ea, const FHESecKey& secretKey){
    
//     ZZX             tagPoly;
//     ZZ              tag,
//                     tmpHash,
//                     msgHash;
//     vector<long>    tagPtxt;
//     long            tagPower;

//     ea.decrypt(tagCtxt, secretKey, tagPtxt);
//     ea.encode(tagPoly, tagPtxt);
//     vecToZZ(tag, tagPoly);
//     tagPower = tag % DLGROUPORDER;
//     generateAuthGroup(generator, authGroup);
//     power(tagDL, generator, tagPower);

//     #pragma omp parallel for
//     for(unsigned long i = 0; i < THRESHOLD; i++){
//         power(msgHash, generator, i);
//         hashing(tmpHash, msgHash);
//         authGroup.push_back(tmpHash);
//     }
// }

// bool verification(const long& generator, const vector<ZZ>& authGroup, const ZZ& tagDL){
//     int     sizeGroup = authGroup.size();
//     bool    isInGroup = false;
//     ZZ      recoverMsgHash = tagDL;

//     // recover g^msg
//     recoverMsg();
//     // check in authentication group
//     #pragma omp parallel for
//     for(unsigned long i = 0; i < THRESHOLD; i++){
//         if(recoverMsgHash == authGroup[i]){
//             isInGroup = true;
//             break;
//         }
//     }

//     return isInGroup;
// }