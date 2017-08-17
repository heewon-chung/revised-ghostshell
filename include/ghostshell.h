#ifndef GHOSTSHELL_H
#define GHOSTSHELL_H

#include <cstdlib>
#include <cassert>
#include <vector>

#include "FHE.h"

#include "constant.h"
#include "generalTools.h"
#include "irisEncoding.h"
#include "match.h"
#include "otm.h"
#include "authGroup.h"

void enrollment(vector<Ctxt>&, const vector<ZZX>&, const FHESecKey&);
void requestAuthenticate(vector<Ctxt>&, const vector<ZZX>&, const FHESecKey&);
void computeHDandOTM(Ctxt&, ZZ&, ZZ&, const vector<Ctxt>&, const vector<Ctxt>&);
void decryptAndGenerateAuthGroup(long&, vector<ZZ>&, ZZ&, const Ctxt&, const FHESecKey&);
bool isValidity(const ZZ&, const long&, const vector<ZZ>&, const ZZ&, const ZZ&);

#endif