#include <stdio.h>

typedef unsigned char       UINT8;
typedef unsigned int        UINT32;
typedef unsigned long long  UINT64;

int main (int argc, char* argv[])
{
    (void)argc;
    (void)argv;

    printf("sizeof(UINT64): %d\n", sizeof(UINT64));
}
