#ifndef MSGENCODING_H
#define MSGENCODING_H

#include <cstdlib>
#include <cassert>
#include <vector>

#include "generalTools.h"
#include "NTL/ZZ.h"
#include "NTL/ZZX.h"

void msgEncode(vector<ZZX>&, const vector<long>&, const long);

#endif