#ifndef GHOSTSHELL_H
#define GHOSTSHELL_H

#include <cstdlib>
#include <cassert>
#include <vector>

#include "FHE.h"

#include "constant.h"
#include "irisEncoding.h"
#include "match.h"
#include "otm.h"
#include "hashing.h"

void enrollment(vector<Ctxt>&, const vector<ZZX>&, const FHESecKey&);
void authentication(vector<Ctxt>&, const vector<ZZX>&, const FHESecKey&);
void computeHDandOTM(Ctxt& tagCtxt, ZZ&, ZZ&, const vector<Ctxt>&, const vector<Ctxt>&);
// void decryptAndGenerateAuthGroup(ZZ&, long&, vector<ZZ>&, const Ctxt&, const EncryptedArray&, const FHESecKey&);
// bool verification(const long&, const vector<ZZ>&, const ZZ&);

#endif