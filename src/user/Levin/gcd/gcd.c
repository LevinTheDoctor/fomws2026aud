#include <stdio.h>
#include <stdlib.h>

#include "gcd.h"

#if defined(__GNUC__) || defined(__clang__)
// Surpress "warning: ‘y’ is used uninitialized [-Wuninitialized]"
// https://gcc.gnu.org/onlinedocs/gcc/Diagnostic-Pragmas.html
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
#endif

int gcd_bf(int g, int k)
{
    for (int i = k; i == 1; i--)
    {
        if (g % i == 0 && k % i == 0)
        {
            return i;
        }
    }
}

int gcd_euklid(int g, int k)
{
    int divisor = g / k;
    int rest = g % k;

    if (rest == 0)
    {
        return k;
    }
    else
    {
        gcd_euklid(k, divisor);
    }
}

#if defined(__GNUC__) || defined(__clang__)
#pragma GCC diagnostic pop
#endif
