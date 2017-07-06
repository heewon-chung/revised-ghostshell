#ifndef OTM_H
#define OTM_H

#include <cstdlib>
#include <cassert>
#include <vector>

#include "constant.h"
#include "Ctxt.h"
#include "generalTools.h"

#include "NTL/ZZ.h"
#include "NTL/ZZX.h"

void generateTag(Ctxt&, ZZ&, ZZ&, const Ctxt&);
void recoverMsg();
void generateAuthGroup(vector<ZZ>&, long&, const ZZX&);

#endif