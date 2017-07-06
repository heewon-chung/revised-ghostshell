#ifndef CONSTANT_H
#define CONSTANT_H

#include "NTL/ZZ.h"

using namespace NTL;

const long          PRIMEFIELD      = 401;
const long          DEGREE          = 1;
const long          SECURITY        = 80;
const long          D               = 0;
const long          C               = 3;

const unsigned long NUMBITS         = 400;
const unsigned long THRESHOLD       = 100;

const unsigned long RANDOMBIT       = 40;
const unsigned long GENERATORBIT    = 30;
const unsigned long DLGROUPORDER    = 100;

const ZZ            MSGRND1         = RandomBits_ZZ(RANDOMBIT);
const ZZ            MSGRND2         = RandomBits_ZZ(RANDOMBIT);

#endif