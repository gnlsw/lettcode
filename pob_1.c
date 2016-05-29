#include <stdio.h>
#include <stdlib.h>

int *twoSum(int* nums, int numSize, int target);

#define ARRAY_SIZE 4

int main()
{
    int nums[ARRAY_SIZE] = {3, 2, 4, 0};
    int target = 6;
    int *ptr;

    ptr = twoSum(nums, ARRAY_SIZE, target);
    if(0 == ptr)
    {
        return 1;
    }
    printf("index_0 = %d, index_1 = %d\n", ptr[0], ptr[1]);

    return 0;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target)
{
    int index_1;
    int index_2;
    int *ptr;
    if(0 == nums)
    {
        printf("input array is null\n");
        return 0;
    }

    for(index_1 = 0; index_1 < numsSize; index_1++)
    {
        for(index_2 = index_1 + 1; index_2 < numsSize; index_2++)
        {
            if(nums[index_1] + nums[index_2] == target)
            {
                ptr = (int *)malloc(sizeof(int) * 2);
                if(0 == ptr)
                {
                    printf("malloc fail\n");
                    return 0;
                }
                ptr[0] = index_1;
                ptr[1] = index_2;
                return ptr;
            }
        }
    }
    return 0;
}
