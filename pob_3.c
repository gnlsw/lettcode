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
    int dw_index;
    int dw_len_index;
    int dw_max = 0;

    dw_strlen = strlen(s);
    pdw_len = (int *)malloc(sizeof(int) * dw_strlen * dw_strlen);

    for(dw_row = 0; dw_row < dw_strlen; dw_row++)
    {
        for(dw_col = 0; dw_col < dw_strlen; dw_col++)
        {
            dw_len_index = dw_row * dw_strlen + dw_col;
            pdw_len[dw_len_index] = 0;
        }
    }

    for(dw_row = 0; dw_row < dw_strlen; dw_row++)
    {
        dw_len_index = dw_row * dw_strlen + dw_row;
        pdw_len[dw_len_index] = 1;
    }

    for(dw_row = 0; dw_row < dw_strlen; dw_row++)
    {
        for(dw_col = dw_row + 1; dw_col < dw_strlen; dw_col++)
        {
            dw_len_index = dw_row * dw_strlen + dw_col - 1;
            if(0 == pdw_len[dw_len_index])
            {
                pdw_len[dw_len_index + 1] = 0;
                continue;
            }

            for(dw_index = dw_row; dw_index <= dw_col; dw_index++)
            {
                if(s[dw_index] == s[dw_col])
                {
                    break;
                }
            }
            if(dw_index == dw_col)
            {
                pdw_len[dw_len_index + 1] = pdw_len[dw_len_index] + 1;
            }
            else
            {
                pdw_len[dw_len_index + 1] = 0;
            }
        }
    }


    for(dw_row = 0; dw_row < dw_strlen; dw_row++)
    {
        for(dw_col = 0; dw_col < dw_strlen; dw_col++)
        {
            dw_len_index = dw_row * dw_strlen + dw_col;
            if(pdw_len[dw_len_index] > dw_max)
            {
                dw_max = pdw_len[dw_len_index];
            }
        }
    }

    return dw_max;
}
