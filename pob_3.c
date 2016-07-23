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
    int dw_begin;
    int dw_end;
    int dw_index;
    int dw_max = 0;
    int dw_current_len = 0;

    dw_strlen = strlen(s);
    if(0 == dw_strlen)
    {
        return 0;
    }

    dw_max = 1;
    dw_current_len = 1;
    for(dw_begin = 0, dw_end = 1; dw_begin < dw_strlen - dw_max; )
    {
        for(; dw_end < dw_strlen; dw_end++)
        {
            for(dw_index = dw_begin; dw_index < dw_end; dw_index++)
            {
                if(s[dw_end] == s[dw_index])
                {
                    dw_begin = dw_index + 1;
                    dw_current_len = dw_end - dw_begin + 1;
                    dw_end++;
                    break;
                }
            }
            if(dw_index == dw_end)
            {
                dw_current_len++;
            }
            else
            {
                break;
            }
            if(dw_current_len > dw_max)
            {
                dw_max = dw_current_len;
            }
        }
    }

    return dw_max;
}
