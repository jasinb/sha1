#include <assert.h>
#include <ctype.h>
#include "sha1.h"


SHA1_Digest SHA1_Digest_fromStr (const char* src)
{
    // \todo why does msvc require this initializer to not issue C4701 ?
    SHA1_Digest d = { "" }; 
    int i;
    
    assert(src); // also, src must be at least 40 bytes
    for (i = 0; i < 20; i++)
    {
        // \todo just use atoi or something
        int c0 = tolower(*src++);
        int c1 = tolower(*src++);

        c0 = '0' <= c0 && c0 <= '9' ? c0 - '0' : ('a' <= c0 && c0 <= 'f' ? 0xa + c0 - 'a' : -1);
        c1 = '0' <= c1 && c1 <= '9' ? c1 - '0' : ('a' <= c1 && c1 <= 'f' ? 0xa + c1 - 'a' : -1);
        d.digest[i] = (UINT8)((c0 << 4) | c1);
    }

    return d;
}

void SHA1_Digest_toStr (const SHA1_Digest* digest, char* dst)
{
    int i;
    assert(digest && dst); // dst must be at least 41 bytes (terminator)
    for (i = 0; i < 20; i++)
    {
        int c0 = digest->digest[i] >> 4;
        int c1 = digest->digest[i] & 0xf;

        assert(0 <= c0 && c0 <= 0xf);
        assert(0 <= c1 && c1 <= 0xf);
        c0 = c0 <= 9 ? '0' + c0 : 'a' + c0;
        c1 = c1 <= 9 ? '0' + c1 : 'a' + c1;

        *dst++ = (char)c0;
        *dst++ = (char)c1;
    }
    *dst = '\0';
}

SHA1_Digest SHA1_get (const void* msg, UINT64 bytes)
{
    // \todo why does msvc require this initializer to not issue C4701 ?
    SHA1_Digest d = { "" };
    
    // \todo implement
    (void)msg;
    (void)bytes;
    return d;
}
