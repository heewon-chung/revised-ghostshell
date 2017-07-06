#ifndef MSGENCODING_H
#define MSGENCODING_H

#include <cstdlib>
#include <cassert>
#include <vector>

#include "EncryptedArray.h"
#include "generalTools.h"
#include "NTL/ZZ.h"

void enrollMsgEncode(vector<NewPlaintextArray>&, const vector<long>&, const EncryptedArray& ea);
void authMsgEncode(vector<NewPlaintextArray>&, const vector<long>&, const EncryptedArray& ea);

#endif