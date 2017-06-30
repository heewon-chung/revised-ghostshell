#include <cstdlib>
#include <vector>

#include "EncryptedArray.h"
#include "Ctxt.h"

#include "mac.h"

using namespace std;
using namespace NTL;

int main(void){
    srand(time(NULL));
    SetSeed(conv<ZZ>(time(NULL)));
}