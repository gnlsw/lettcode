#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef unsigned int VOS_UINT32;
VOS_UINT32 manacher(char *aucStr);

int main()
{
    char aucStr[] = "ffbcdcbggbcdcbgg";
    manacher(aucStr);

    return 0;
}

VOS_UINT32 manacher(char *aucStr)
{
    VOS_UINT32 udwLen = strlen(aucStr);
    VOS_UINT32 udwIndex;
    VOS_UINT32 udwNewLen = 2 * udwLen + 2;
    VOS_UINT32 *audwRadiusLen = (VOS_UINT32 *)malloc(udwNewLen * sizeof(VOS_UINT32));
    
    VOS_UINT32  udwMaxRight = 0;
    VOS_UINT32  udwPos = 0;
    VOS_UINT32  udwRadiusLen;
    VOS_UINT32  udwMax = 0;
    VOS_UINT32  udwRstIndex = 0;
    char *aucNewStr = (char *)malloc(udwNewLen + 1);
    char *aucRst;

    memset(audwRadiusLen, 0, sizeof(VOS_UINT32) * udwNewLen);    
    memset(aucNewStr, 0, udwNewLen);
    aucNewStr[0] = '^';
    aucNewStr[1] = '#';
    for(udwIndex = 0; udwIndex < udwLen; udwIndex++)
    {
        aucNewStr[2 + 2 * udwIndex] = aucStr[udwIndex];
        aucNewStr[3 + 2 * udwIndex] = '#';
    }

    

    audwRadiusLen[0] = 1;
    for(udwIndex = 1; udwIndex < udwNewLen; udwIndex++)
    {
        if(udwIndex > udwMaxRight)
        {
            udwRadiusLen = 1;
        }
        else
        {
            if(audwRadiusLen[2 * udwPos - udwIndex] < udwMaxRight - udwIndex)
            {
                udwRadiusLen = audwRadiusLen[2 * udwPos - udwIndex];
            }
            else
            {
                udwRadiusLen = udwMaxRight - udwIndex;
            }
            
        }

        for(;;)
        {
            if(aucNewStr[udwIndex + udwRadiusLen] == aucNewStr[udwIndex - udwRadiusLen])
            {
                udwRadiusLen++;
            }
            else
            {
                break;
            }
        }

        audwRadiusLen[udwIndex] = udwRadiusLen;
    }


    for(udwIndex = 1; udwIndex < udwNewLen; udwIndex++)
    {
        if(audwRadiusLen[udwIndex] > udwMax)
        {
            udwMax = audwRadiusLen[udwIndex];
            udwPos = udwIndex;
        }
    }

    aucRst = (char *)malloc(udwMax);
    memset(aucRst, 0, udwMax);
    for(udwRstIndex = 0, udwIndex = udwPos - udwMax + 1; udwIndex < udwPos + udwMax; udwIndex++)
    {
        if('#' != aucNewStr[udwIndex])
        {
            aucRst[udwRstIndex] = aucNewStr[udwIndex];
            udwRstIndex++;
        }
        
    }

    printf("%s\n", aucRst);

    return 0;
}
