#ifndef OTM_H
#define OTM_H

#include <cstdlib>
#include <cassert>
#include <vector>

#include "constant.h"
#include "EncryptedArray.h"
#include "Ctxt.h"
#include "FHE.h"
#include "generalTools.h"

#include "NTL/ZZ.h"
#include "NTL/ZZX.h"

void generateTag(Ctxt&, ZZ&, ZZ&, const Ctxt&);
void recoverMsg(ZZX&, const ZZ&, const ZZ&, const ZZX&);
void recoverMsg(ZZ&, const ZZ&, const ZZ&, const ZZX&);

#endif