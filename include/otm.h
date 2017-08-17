#ifndef OTM_H
#define OTM_H

#include <cstdlib>
#include <cassert>
#include <vector>

#include "FHE.h"

#include "NTL/ZZ.h"
#include "NTL/ZZX.h"

#include "constant.h"
#include "generalTools.h"

void generateTag(Ctxt&, ZZ&, ZZ&, const Ctxt&);
void recoverMsg(ZZX&, const ZZ&, const ZZ&, const ZZX&);
void recoverMsg(ZZ&, const ZZ&, const ZZ&, const ZZX&);
void recoverMsg(ZZ&, const ZZ&, const long&, const ZZ&, const ZZ&);

#endif