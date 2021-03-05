#include "mRNG.h"

int abs(int num) {
    if (num == 0) return 0;
    else if (num < 0) return -num;
    else return num;
}

unsigned long long bitRotate(unsigned long long num, long long count) // Positive rotates left, negative rotates right
{
    int rot = count % 64;
    if (rot == 0) return num;
    else if(rot > 0) return (num >> (64 - rot)) | (num << rot);
    else return (num << abs(rot)) | (num >> abs(rot));
}

unsigned long long oddSquare(unsigned long long num)
{
    return num * bitRotate(num, (long long)num);
}

unsigned long long mRNG(unsigned long long seed, unsigned long long count)
{
    unsigned long long n1, n2, n3, n4;
    n1 = oddSquare(seed) ^ count;
    n2 = seed ^ oddSquare(count);
    n3 = oddSquare(n1) ^ seed;
    n4 = oddSquare(n2) ^ count;
    return oddSquare(n3) ^ oddSquare(n4);
}
