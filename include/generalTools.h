#ifndef GENERALTOOLS_H
#define GENERALTOOLS_H

#include <cstdlib>
#include <cassert>
#include <vector>

#include "NTL/ZZ.h"
#include "NTL/ZZX.h"
#include "constant.h"

using namespace std;
using namespace NTL;

void ZZtoZZX(ZZX&, const ZZ&);
void ZZXtoZZ(ZZ&, const ZZX&);
void generateVectorInstance(vector<ZZX>&);

#endif