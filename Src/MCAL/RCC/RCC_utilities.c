/*
 * RCC_utilities.c
 *
 *  Created on: Sep 5, 2023
 *      Author: BLU-RAY
 */


#include "RCC_utilities.h"

long long gcd(long long a, long long b)
{
    if (a == 0)
        return b;
    else if (b == 0)
        return a;
    if (a < b)
        return gcd(a, b % a);
    else
        return gcd(b, a % b);
}


// Function to convert decimal to fraction
uint32* decimal_to_fraction(double decimal)
{
    int denimnator = 1;
    while(decimal != (int)decimal)
    {
        decimal *= 10;
        denimnator *= 10;
    }

    int divider = gcd(decimal, denimnator);
    decimal /= divider;
    denimnator /= divider;
    uint32 *temp = (uint32 *)malloc(2 * sizeof(uint32));
    temp[0] = decimal;
    temp[1] = denimnator;
    return temp;

}
