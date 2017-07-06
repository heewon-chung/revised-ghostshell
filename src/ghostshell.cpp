#include "ghostshell.h"

using namespace std;
using namespace NTL;

void enrollment(vector<Ctxt>& encIris, ZZ& rnd, const vector<long>& iris, const EncryptedArray& ea, const FHESecKey& secretKey){
    assert(iris.size() == NUMBITS);
    vector<NewPlaintextArray> encodedIris(NUMBITS + 1, ea);

    msgEncode(encodedIris, iris, ea);
    assert(encodedIris.size() == NUMBITS + 1);
    
    for(unsigned long i = 0; i < encodedIris.size(); i++){
        ea.encrypt(encIris[i], secretKey, encodedIris[i]);
    }
}

void authnetication(){

}