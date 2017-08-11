#ifndef GENERALTOOLS_H
#define GENERALTOOLS_H

#include <cstdlib>
#include <cassert>
#include <vector>

#include "constant.h"
#include "EncryptedArray.h"
#include "NTL/ZZ.h"

using namespace std;
using namespace NTL;

void generateVectorInstance(vector<ZZX>&);
void generateVectorInstance(vector<vector<ZZX>>&, const EncryptedArray&);
void ZZtoZZX(ZZX&, const ZZ&);
void ZZtoZZX(ZZX&, const int&);

#endif