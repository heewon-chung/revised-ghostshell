#include <cstdlib>
#include <vector>

#include "EncryptedArray.h"
#include "FHE.h"

#include "constant.h"
#include "irisEncoding.h"
#include "ghostshell.h"
#include "utilities.h"

using namespace std;
using namespace NTL;

int main(void){

    test;
    
    srand(time(NULL));
    SetSeed(conv<ZZ>(time(NULL)));

    cout << "\nRevised Ghostshell Test Started...\n";
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
    vector<ZZX> iris1, iris2;
    generateVectorInstance(iris1);
    generateVectorInstance(iris2);

    // Polynomial CRT
    // vector<vector<ZZX>> iris1, iris2;
    // generateVectorInstance(iris1, ea);
    // generateVectorInstance(msg2, ea);

    long ptxtHD = hammingDistance(iris1, iris2);

    /*
        Variables for Ghostshell
    */
    long            generator;
    ZZ              maskAdd, maskMul, tagDL;
    vector<ZZ>      authGroup(THRESHOLD);
    ZZX             resPoly;
    vector<ZZX>     encodedIris1, encodedIris2;
    Ctxt            tagCtxt(secretKey);
    vector<Ctxt>    encIris1(NUMBITS + 1, secretKey),
                    encIris2(NUMBITS + 1, secretKey);
    TIMER           start, end;

    cout << "\nClient: \tEncryption Iris for Enrollment... ";
    start = TIC;
    enrollment(encIris1, iris1, secretKey);
    end = TOC;
    cout << get_time_us(start, end, 1000000) << " sec\n";

    cout << "Client: \tEncrypting Iris for Authentication... ";
    start = TIC;
    requestAuthenticate(encIris2, iris2, secretKey);
    end = TOC;
    cout << get_time_us(start, end, 1000000) << " sec\n";

    cout << "Server: \tComputing Hamming Distance and Generating Tag... ";
    start = TIC;
    computeHDandOTM(tagCtxt, maskAdd, maskMul, encIris1, encIris2);
    end = TOC;
    cout << get_time_us(start, end, 1000000) << " sec\n";

    cout << "Client: \tDecrypting and Generating Authentication Group... ";
    start = TIC;
    // secretKey.Decrypt(resPoly, tagCtxt);
    // recoverMsg(resPoly, maskAdd, maskMul, resPoly);
    decryptAndGenerateAuthGroup(generator, authGroup, tagDL, tagCtxt, secretKey);
    end = TOC;
    cout << get_time_us(start, end, 1000000) << " sec\n";

    cout << "Server: \tChecking Validity... ";
    start = TIC;
    bool result = isValidity(tagDL, generator, authGroup,maskAdd, maskMul);
    end = TOC;
    cout << get_time_us(start, end, 1000000) << " sec\n";

    cout << "\nOriginal Hamming Distance (plaintext): " << ptxtHD << endl;
    cout << "Recover Hamming Distance (ciphertext): " << resPoly << endl;
    cout << "Protocol Result (plaintext): " << (ptxtHD < THRESHOLD) << endl;
    cout << "Protocol Result (ciphertext): " << result << endl;
    cout << "Homomorphic Levels Left: " << tagCtxt.findBaseLevel() << endl;

    return 0;
}