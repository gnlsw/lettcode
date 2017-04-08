#include "stdio.h"
#include "string.h"

int myAtoi(char *str);

int main()
{
    char * auc_var = "1234";
    int    int_var = myAtoi(auc_var);

    printf("%d\n", int_var);

    return 0;
}

int myAtoi(char *str)
{
    int sum = 0;
    int loop;
    int int_strlen = strlen(str);

    /* input null, return 0 */
    if(0 == int_strlen)
    {
        return 0;
    }

    /* check illegal char */
    for(loop = 0; loop < int_strlen; loop++)
    {
        if(str[loop] < '0' || str[loop] > '9')
        {
            return 0;
        }
    }

    for(loop = 0; loop < int_strlen; loop++)
    {
        sum = sum * 10 + (str[loop] - '0');
    }

    return sum;

}