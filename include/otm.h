#ifndef MAC_H
#define MAC_H

#include <cstdlib>
#include <cassert>
#include <vector>

#include "EncryptedArray.h"
#include "Ctxt.h"

#include "NTL/ZZ.h"
#include "NTL/ZZX.h"

void generateTag(Ctxt&, ZZX&, ZZX&, const Ctxt&, const EncryptedArray&);
void recoverMsg();

#endif