#include <cstdlib>
#include <vector>

#include "EncryptedArray.h"
#include "Ctxt.h"

#include "ghostshell.h"

using namespace std;
using namespace NTL;

int main(void){
    srand(time(NULL));
    SetSeed(conv<ZZ>(time(NULL)));   
}