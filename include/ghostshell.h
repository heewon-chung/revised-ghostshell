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

// void setParameter();
void enrollment(vector<Ctxt>&, ZZ&, const vector<long>&, const long, const EncryptedArray&, const FHESecKey&);
void authentication();

#endif