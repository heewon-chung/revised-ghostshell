#ifndef CONSTANT_H
#define CONSTANT_H

#include "NTL/ZZ.h"

using namespace NTL;

const long  MSGSPACE        = 401;
const long  DEGREE          = 1;
const long  SECURITY        = 80;
const long  LEVEL           = 4;
const long  D               = 0;
const long  C               = 3;

const long  NUMBITS         = 400;
const long  THRESHOLD       = 100;
const long  POLYMODULUS     = 2;

const long  RANDOMBIT       = 40;
const long  GENERATORBIT    = 30;
const long  DLGROUPORDER    = 100;

const ZZ    MASKRND         = conv<ZZ>(425175407133);   // random 40 bit integer
const ZZ    MSGRND1         = conv<ZZ>(0);
const ZZ    MSGRND2         = MSGRND1 + 1;

#endif