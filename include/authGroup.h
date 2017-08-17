#ifndef AUTHGROUP_H
#define AUTHGROUP_H

#include <cstdlib>
#include <vector>

#include "NTL/ZZ.h"

#include "constant.h"

using namespace std;
using namespace NTL;

void generateAuthGroup(long&, vector<ZZ>&);
bool isInGroup(const ZZ&, const vector<ZZ>&);

#endif