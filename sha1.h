#pragma once

#include <stdint.h>

// don't just forward declare as we want to pass it around by value
typedef struct _SHA1Digest
{
    uint32_t digest[5];
} SHA1Digest;

SHA1Digest SHA1_strToDigest (const char* src);
void       SHA1_digestToStr (const SHA1Digest* digest, char* dst);
SHA1Digest SHA1_get (const void* msg, uint64_t bytes);
