#include <cstdlib>
#include <vector>

#include "constant.h"
#include "EncryptedArray.h"
#include "Ctxt.h"

#include "match.h"
#include "generalTools.h"

using namespace std;
using namespace NTL;

int main(void){
    srand(time(NULL));
    SetSeed(conv<ZZ>(time(NULL)));

    cout << "Matching Algorithm Test Started...\n";
    long L = 3;
    long m = FindM(SECURITY, L, C, PRIMEFIELD, D, 0, 0);
    
    FHEcontext context(m, PRIMEFIELD, DEGREE);
    buildModChain(context, L);
    ZZX F = context.alMod.getFactorsOverZZ()[0];

    cout << "Generating Keys... \n";
    FHESecKey secretKey(context);
    // const FHEPubKey& publicKey = secretKey;
    secretKey.GenSecKey(SECURITY);

    cout << "Generating Frobenius and SIMD Matrices... \n";
    addFrbMatrices(secretKey);
    addSome1DMatrices(secretKey);

    const EncryptedArray ea(context, F);

    /*
        Message Generation
    */
    vector<ZZX> msg1, msg2;
    
    generateVectorInstance(msg1);
    generateVectorInstance(msg2);

    long ptxtHD = hammingDistance(msg1, msg2);

    vector<vector<ZZX>> msg1Poly(NUMBITS), msg2Poly(NUMBITS);

    for(unsigned long i = 0; i < NUMBITS; i++){
        ea.decode(msg1Poly[i], msg1[i]);
        ea.decode(msg2Poly[i], msg2[i]);
    }

    Ctxt            ctxtHD(secretKey);
    vector<Ctxt>    encIris1(NUMBITS, secretKey), 
                    encIris2(NUMBITS, secretKey);
    vector<long>    decHD;
    ZZX             hdPoly;

    cout << "Encrypting Messages..." << endl;
    #pragma omp parallel for
    for(unsigned long i = 0; i < NUMBITS; i++){
        ea.encrypt(encIris1[i], secretKey, msg1Poly[i]);
        ea.encrypt(encIris2[i], secretKey, msg2Poly[i]);
    }

    cout << "Computing Hamming Distance..." << endl;
    hammingDistance(ctxtHD, encIris1, encIris2);

    ea.decrypt(ctxtHD, secretKey, decHD);

    ea.encode(hdPoly, decHD);

    cout << "\nLength of Two Vector:" << NUMBITS << endl;
    cout << "Hamming Distance (plaintext): " << ptxtHD << endl;
    cout << "Hamming Distance (ciphertext): " << hdPoly << endl;
    cout << "Hamming Distance Levels Left: " << ctxtHD.findBaseLevel() << endl;
    // cout << "Evaluation time for Hamming Distance: " << get_time_us(start, end, 1) / 1000000 << " sec" << endl;

    return 0;
}