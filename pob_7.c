#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int reverse(int x);

int main()
{
    int dw_var = -2147483412;
    int dw_rev = reverse(dw_var);
    
    printf("dw_var = %d, dw_rev = %d\n", dw_var, dw_rev);
}

int reverse(int x)
{
    int dw_abs;
    int dw_var;
    int dw_remainder;

    if(x < 0)
    {
        dw_abs = (-1) * x;
    }
    else
    {
        dw_abs = x;
    }
    
    dw_var = 0;
    while(dw_abs != 0)
    {
        dw_remainder = dw_abs % 10;
        dw_abs = dw_abs / 10;

        if((dw_var == 0) || (INT_MAX / dw_var >= 10))
        {
            dw_var = dw_var * 10;
        }
        else
        {
            return 0;
        }
        if((INT_MAX - dw_var) > dw_remainder)
        {
            dw_var = dw_var + dw_remainder;
        }
        else
        {
            return 0;
        }
    }

    if(x < 0)
    {
        dw_var = (-1) * dw_var;
    }

    return dw_var;
}