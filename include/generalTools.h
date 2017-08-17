#ifndef GENERALTOOLS_H
#define GENERALTOOLS_H

#include <cstdlib>
#include <cassert>
#include <vector>

#include "EncryptedArray.h"

#include "NTL/ZZ.h"

#include "constant.h"

using namespace std;
using namespace NTL;

void generateVectorInstance(vector<ZZX>&);
void generateVectorInstance(vector<vector<ZZX>>&, const EncryptedArray&);
void ZZtoZZX(ZZX&, const ZZ&);
void ZZtoZZX(ZZX&, const int&);
ZZ ZZXtoZZ(const ZZX&);
void ZZXtoZZ(ZZ&, const ZZX&);

#endif