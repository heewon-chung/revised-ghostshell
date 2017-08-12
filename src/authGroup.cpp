#include "authGroup.h"

// void generateAuthGroup(long& generator, vector<ZZ>& authGroup){
//     authGroup.clear();
//     authGroup.resize(THRESHOLD);

//     RandomBits(generator, GENERATORBIT);
    
//     ZZ rnd = MASKRND;
//     power(rnd, rnd, 2);

//     #pragma omp parallel for
//     for(unsigned long i = 0; i < THRESHOLD; i++){
//         long exponent = (rnd + i) % DLGROUPORDER;
//         power(authGroup[i], generator, exponent);
//     }
// }