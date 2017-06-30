#ifndef UTILITIES_H
#define UTILITIES_H

#include <cstdlib>
#include <cassert>
#include <vector>

#include "NTL/ZZ.h"

using namespace std;
using namespace NTL;

// void multiplyAllPrimes(ZZ&, const vector<long>&);
ZZ multiplyAllPrimes(const vector<long>&);

#endif