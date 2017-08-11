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
    srand(time(NULL));
    SetSeed(conv<ZZ>(time(NULL)));

    cout << "\nRevised Ghostshell Test Started..." << endl;
    long L = 5;
    long m = FindM(SECURITY, L, C, PRIMEFIELD, D, 0, 0);
    FHEcontext context(m, PRIMEFIELD, DEGREE);
    buildModChain(context, L);
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
    ZZ              maskAdd, maskMul;
    vector<ZZX>     encodedIris1, encodedIris2;
    Ctxt            tagCtxt(secretKey);
    vector<Ctxt>    encIris1(NUMBITS + 1, secretKey),
                    encIris2(NUMBITS + 1, secretKey);

 
    cout << "Encryption Iris for Enrollment..." << endl;
    enrollment(encIris1, iris1, secretKey);

    cout << "Encrypting Iris for Authentication..." << endl;
    authentication(encIris2, iris2, secretKey);

    cout << "Computing Hamming Distance and Generating Tag..." << endl;
    computeHDandOTM(tagCtxt, maskAdd, maskMul, encIris1, encIris2);
}