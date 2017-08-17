#ifndef MATCHING_H
#define MATCHING_H

#include <cstdlib>
#include <cassert>
#include <vector>

#include "FHE.h"

#include "constant.h"
#include "generalTools.h"

long hammingDistance(const vector<ZZX>&, const vector<ZZX>&);
long hammingDistance(const vector<vector<ZZX>>&, const vector<vector<ZZX>>&);
void hammingDistance(Ctxt&, const vector<Ctxt>&, const vector<Ctxt>&);

#endif