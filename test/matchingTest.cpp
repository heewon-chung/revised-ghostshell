#include <cstdlib>
#include <vector>

#include "EncryptedArray.h"
#include "FHE.h"

#include "constant.h"
#include "generalTools.h"
#include "match.h"
#include "utilities.h"

using namespace std;
using namespace NTL;

int main(void){
    srand(time(NULL));
    SetSeed(conv<ZZ>(time(NULL)));

    cout << "\nMatching Algorithm Test Started...\n";
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

    Ctxt            ctxtHD(secretKey);
    vector<Ctxt>    encMsg1(NUMBITS, secretKey), 
                    encMsg2(NUMBITS, secretKey);
    ZZX             decHD;
    // vector<ZZX>     decHDVec;

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

    TIMER start, end;
    cout << "Computing Hamming Distance..." << endl;
    start = TIC;
    
    hammingDistance(ctxtHD, encMsg1, encMsg2);
    
    end = TOC;

    secretKey.Decrypt(decHD, ctxtHD);
    // ea.decrypt(ctxtHD, secretKey, decHDVec);

    cout << "Hamming Distance (plaintext): " << ptxtHD << endl;
    cout << "Hamming Distance (ciphertext): " << decHD << endl;
    cout << "Homomorphic Levels Left: " << ctxtHD.findBaseLevel() << endl;
    cout << "Evaluation time for Hamming Distance: " << get_time_us(start, end, 1000000) << " sec" << endl;

    return 0;
}