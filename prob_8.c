#include "stdio.h"
#include "string.h"
#include "ctype.h"

int myAtoi(char *str);

int main()
{
    char * auc_var = "  12ac34";
    int    int_var = myAtoi(auc_var);

    printf("%d\n", int_var);

    return 0;
}

int myAtoi(char *str)
{
    int sum  = 0;
    int loop = 0;
    int int_strlen = strlen(str);
    int in_dig = 0;

    if(NULL == str)
    {
        return 0;
    }

    /* input null, return 0 */
    if(0 == int_strlen)
    {
        return 0;
    }

    /* check illegal char */
    while('\0' != str[loop])
    {
        /* not dig yet */
        if(in_dig == 0)
        {
            if(isspace(str[loop]))
            {
                loop++;
                continue;
            }
            else if(isdigit(str[loop]))
            {
                in_dig = 1;
                sum = str[loop] - '0';
                loop++;
            }
            else
            {
                break;
            }
        }
        else
        {

            if(isdigit(str[loop]))
            {
                sum = sum * 10 + (str[loop] - '0');
                loop++;
            }
            else
            {
                break;
            }
        }
    }

    return sum;

}
