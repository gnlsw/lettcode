#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int lengthOfLongestSubstring(char* s);

int main()
{
    char aucstr[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    printf("%d\n", lengthOfLongestSubstring(aucstr));
}

int lengthOfLongestSubstring(char* s)
{
    int dw_strlen;
    int *pdw_len;
    int dw_row;
    int dw_col;
    int dw_begin;
    int dw_end;
    int dw_index;
    int dw_len_index;
    int dw_max = 0;

    dw_strlen = strlen(s);
    if(0 == dw_strlen)
    {
        return 0;
    }
    pdw_len = (int *)malloc(sizeof(int) * dw_strlen);

    for(dw_len_index = 0; dw_len_index < dw_strlen; dw_len_index++)
    {
        pdw_len[dw_len_index] = 0;
    }

    dw_max = 1;
    for(dw_begin = 0; dw_begin < dw_strlen; dw_begin++)
    {
        pdw_len[dw_begin] = 1;
        for(dw_end = dw_begin + 1; dw_end < dw_strlen; dw_end++)
        {
            if(0 == pdw_len[dw_end - 1])
            {
                pdw_len[dw_end] = 0;
                continue;
            }

            for(dw_index = dw_begin; dw_index < dw_end; dw_index++)
            {
                if(s[dw_end] == s[dw_index])
                {
                    break;
                }
            }
            if(dw_index == dw_end)
            {
                pdw_len[dw_index] = pdw_len[dw_index - 1] + 1;
            }
            else
            {
                pdw_len[dw_index] = 0;
            }
            if(pdw_len[dw_end] > dw_max)
            {
                dw_max = pdw_len[dw_end];
            }
        }
    }

    return dw_max;
}
