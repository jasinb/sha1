#pragma once

#include <stdint.h>

// struct so we can return it (it's 5x32bit)
typedef struct _SHA1_Digest
{
    uint8_t digest[20];
} SHA1_Digest;

SHA1_Digest SHA1_Digest_fromStr (const char* src);
void        SHA1_Digest_toStr   (const SHA1_Digest* digest, char* dst);
SHA1_Digest SHA1_get (const void* msg, uint64_t bytes);
