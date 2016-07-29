#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int reverse(int x);

int main()
{
    int dw_var = -2147483648;
    int dw_rev = reverse(dw_var);
    
    printf("dw_var = %d, dw_rev = %d\n", dw_var, dw_rev);
}

int reverse(int x)
{
    long long l_abs;
    long long l_var;
    long long l_remainder;

    if(x < 0)
    {
        l_abs = (-1) * (long long)x;
    }
    else
    {
        l_abs = x;
    }
    
    l_var = 0;
    while(l_abs != 0)
    {
        l_remainder = l_abs % 10;
        l_abs = l_abs / 10;

        l_var = l_var * 10 + l_remainder;
    }

    if(l_var > INT_MAX)
    {
        return 0;
    }

    if(x < 0)
    {
        l_var = (-1) * l_var;
    }

    return (int)l_var;
}