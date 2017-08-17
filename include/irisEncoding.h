#ifndef IRISENCODING_H
#define IRISENCODING_H

#include <cstdlib>
#include <cassert>
#include <vector>

#include "NTL/ZZX.h"

#include "constant.h"
#include "generalTools.h"

void enrollIrisEncode(vector<ZZX>&, const vector<ZZX>&);
void authIrisEncode(vector<ZZX>&, const vector<ZZX>&);

#endif