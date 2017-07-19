#ifndef GHOSTSHELL_H
#define GHOSTSHELL_H

#include <cstdlib>
#include <cassert>
#include <vector>

#include "NTL/ZZ.h"
#include "Ctxt.h"
#include "EncryptedArray.h"

#include "constant.h"
#include "msgEncoding.h"
#include "match.h"
#include "otm.h"
#include "hashing.h"

void enrollment(vector<Ctxt>&, ZZ&, const vector<long>&, const long, const EncryptedArray&, const FHESecKey&);
void authentication(vector<Ctxt>&, ZZ&, const vector<long>&, const long, const EncryptedArray&, const FHESecKey&);
void computeHDandTag(Ctxt& tagCtxt, ZZ&, ZZ&, const vector<Ctxt>&, const vector<Ctxt>&);
void decryptAndGenerateAuthGroup(ZZ&, long&, vector<ZZ>&, const Ctxt&, const EncryptedArray&, const FHESecKey&);
bool verification(const long&, const vector<ZZ>&, const ZZ&);

#endif