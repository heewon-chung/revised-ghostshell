#ifndef UTILITIES_H
#define UTILITIES_H

#include <cstdlib>
#include <cassert>
#include <vector>

#include "NTL/ZZ.h"

using namespace std;
using namespace NTL;

// void multiplyAllPrimes(ZZ&, const vector<long>&);
// ZZ multiplyAllPrimes(const vector<long>&);
void generateVectorInstance(vector<vector<long>>&, const long, const long);
long printAndComputeHD(const vector<vector<long>>&, const vector<vector<long>>&);

#endif