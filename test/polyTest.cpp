#include "generalTools.h"
#include <cstdlib>

#include "NTL/ZZX.h"

using namespace std;
using namespace NTL;

int main(void){
    ZZX resPoly;
    ZZ rnd = RandomBits_ZZ(40);
    ZZtoZZX(resPoly, rnd);
    
    cout << "Random = " << rnd << endl;
    cout << "Poly = " << resPoly << endl;
    cout << "Eval = " << ZZXtoZZ(resPoly) << endl;
}   