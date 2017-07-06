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

void integerToZZX(ZZX&, const ZZ&);
void generateVectorInstance(vector<ZZX>&);

#endif