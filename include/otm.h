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

void generateTag(Ctxt&, ZZ&, ZZ&, const Ctxt&, const EncryptedArray&);
void recoverMsg(ZZX&, const ZZ&, const ZZ&, const ZZX&);
void generateAuthGroup(long&, vector<ZZ>&);

#endif