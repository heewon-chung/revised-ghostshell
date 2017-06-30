#include <cstdlib>
#include <vector>

#include "EncryptedArray.h"
#include "Ctxt.h"

#include "matching.h"

int main(void){
    srand(time(NULL));
    SetSeed(conv<ZZ>(time(NULL)));
}