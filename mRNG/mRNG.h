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

#ifndef mRNG_H
#define mRNG_H

int abs(int num);

unsigned long long bitRotate(unsigned long long num, long long count);

unsigned long long oddSquare(unsigned long long num);

unsigned long long mRNG(unsigned long long seed, unsigned long long count);

#endif
