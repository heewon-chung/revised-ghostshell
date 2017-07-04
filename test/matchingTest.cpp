#include <cstdlib>
#include <vector>

#include "EncryptedArray.h"
#include "Ctxt.h"

#include "match.h"
#include "utilities.h"

using namespace std;
using namespace NTL;

int main(void){
    srand(time(NULL));
    SetSeed(conv<ZZ>(time(NULL)));

    cout << "Matching Algorithm Test Started...\n";
    
    long NUMBITS = 400;

    long p = 401;
    long r = 1;
    long security = 80;
	long d = 0;
	long c = 3;
    long L = 3;
    long m = FindM(security, L, c, p, d, 0, 0);
    
    FHEcontext context(m, p, r);
    buildModChain(context, L);
    ZZX F = context.alMod.getFactorsOverZZ()[0];

    cout << "Generating Keys... \n";
    FHESecKey secretKey(context);
    const FHEPubKey& publicKey = secretKey;
    secretKey.GenSecKey(security);

    cout << "Generating Frobenius and SIMD Matrices... \n";
    addFrbMatrices(secretKey);
    addSome1DMatrices(secretKey);

    const EncryptedArray ea(context, F);
    int numSlots = ea.size();

    vector<vector<long>> msg1, msg2;
    
    generateVectorInstance(msg1, NUMBITS, numSlots);
    generateVectorInstance(msg2, NUMBITS, numSlots);

    long ptxtHD = printAndComputeHD(msg1, msg2);

    vector<Ctxt> encIris1(NUMBITS, publicKey), encIris2(NUMBITS, publicKey);
    Ctxt ctxtHD(publicKey);
    vector<long> decHD;

    #pragma omp parallel for
    for(unsigned long i = 0; i < NUMBITS; i++){
        ea.encrypt(encIris1[i], publicKey, msg1[i]);
        ea.encrypt(encIris2[i], publicKey, msg2[i]);
    }

    hammingDistance(ctxtHD, encIris1, encIris2);

    ea.decrypt(ctxtHD, secretKey, decHD);
    cout << "Hamming Distance (ciphertext)" << decHD[0] << endl;

    return 0;
}