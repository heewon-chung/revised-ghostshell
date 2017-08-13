#include <cstdlib>
#include <vector>

#include "EncryptedArray.h"
#include "FHE.h"

#include "constant.h"
#include "generalTools.h"
#include "match.h"
#include "otm.h"
#include "utilities.h"

using namespace std;
using namespace NTL;

int main(void){
    srand(time(NULL));
    SetSeed(conv<ZZ>(time(NULL)));

    cout << "\nOne-Time MAC Test Started...\n";
    long m = FindM(SECURITY, LEVEL, C, MSGSPACE, D, 0, 0);
    FHEcontext context(m, MSGSPACE, DEGREE);
    buildModChain(context, LEVEL);
    ZZX F = context.alMod.getFactorsOverZZ()[0];

    cout << "Generating Keys... \n";
    FHESecKey secretKey(context);
    secretKey.GenSecKey(SECURITY);

    cout << "Generating Frobenius and SIMD Matrices... \n";
    addFrbMatrices(secretKey);
    addSome1DMatrices(secretKey);

    const EncryptedArray ea(context, F);

    /*
        Message Generation
    */
    // Polynomial
    vector<ZZX> msg1, msg2;
    generateVectorInstance(msg1); 
    generateVectorInstance(msg2);

    // Polynomial CRT
    // vector<vector<ZZX>> msg1, msg2;
    // generateVectorInstance(msg1, ea);
    // generateVectorInstance(msg2, ea);

    long ptxtHD = hammingDistance(msg1, msg2);

    Ctxt            ctxtTag(secretKey);
    vector<Ctxt>    encMsg1(NUMBITS, secretKey), 
                    encMsg2(NUMBITS, secretKey);
    ZZ              maskAdd, maskMul, recHD;
    ZZX             tagPoly;

    cout << "Encrypting Messages..." << endl;
    #pragma omp parallel for
    for(unsigned long i = 0; i < NUMBITS; i++){
        // Polynomial
        secretKey.Encrypt(encMsg1[i], msg1[i]);
        secretKey.Encrypt(encMsg2[i], msg2[i]);
        // Polynomial CRT
        // ea.skEncrypt(encMsg1[i], secretKey, msg1[i]);
        // ea.skEncrypt(encMsg2[i], secretKey, msg2[i]);
    }

    cout << "Computing Hamming Distance..." << endl;
    hammingDistance(ctxtTag, encMsg1, encMsg2);

    TIMER start, end;
    cout << "Generating One-Time MAC for Ctxt..." << endl;
    start = TIC;
    
    generateTag(ctxtTag, maskAdd, maskMul, ctxtTag);

    end = TOC;

    secretKey.Decrypt(tagPoly, ctxtTag);
    recoverMsg(recHD, maskAdd, maskMul, tagPoly);
    // recoverMsg(recPoly, maskAdd, maskMul, tagPoly);

    
    cout << "Original Message (plaintext): " << ptxtHD << endl;
    cout << "Recover Message (ciphertext): " << recHD << endl;
    cout << "Homomorphic Levels Left: " << ctxtTag.findBaseLevel() << endl;
    cout << "Evaluation time for Generating Tag: " << get_time_us(start, end, 1000000) << " sec\n" << endl;

    return 1;
}