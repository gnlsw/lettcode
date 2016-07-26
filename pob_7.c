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
    int dw_quot;
    int dw_count;
    int dw_index;
    int dw_var;
    int *pdw_arr;

    if((x > -10) && (x < 10))
    {
        return x;
    }

    if(x < 0)
    {
        dw_abs = (-1) * x;
    }
    else
    {
        dw_abs = x;
    }
    
    dw_quot  = dw_abs;
    dw_count = 0;
    while(0 != dw_quot)
    {
        dw_quot = dw_quot / 10;
        dw_count++;
    }

    pdw_arr = (int *)malloc(sizeof(int) * dw_count);
    memset(pdw_arr, 0, sizeof(int) * dw_count);
    dw_quot = dw_abs;
    dw_count = 0;
    while(0 != dw_quot)
    {
        pdw_arr[dw_count] = dw_quot % 10;
        dw_quot           = dw_quot / 10;
        dw_count++;
    }

    dw_var = pdw_arr[0];
    for(dw_index = 1; dw_index < dw_count; dw_index++)
    {
        if((dw_var == 0) || (INT_MAX / dw_var >= 10))
        {
            dw_var = dw_var * 10;
        }
        else
        {
            return 0;
        }
        if((INT_MAX - dw_var) > pdw_arr[dw_index])
        {
            dw_var = dw_var + pdw_arr[dw_index];
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