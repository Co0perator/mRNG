/************************************************************************    
    This software can be used to generate pseudo-random numbers
    
    Copyright (C) 2021-2024  Miles Potter

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
    
***************************************************************************/

#include "mRNG.h"

int abs(int num) 
{
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
