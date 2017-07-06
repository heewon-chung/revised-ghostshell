#ifndef MATCHING_H
#define MATCHING_H

#include <cstdlib>
#include <cassert>
#include <vector>

#include "constant.h"
#include "Ctxt.h"


long hammingDistance(const vector<ZZX>&, const vector<ZZX>&);
void hammingDistance(Ctxt&, const vector<Ctxt>&, const vector<Ctxt>&);

#endif