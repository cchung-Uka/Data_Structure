#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

int removeDuplicates(int* nums, int numsSize)
{
    assert(nums);

    int src = 1;
    int dest = 1;

    while (src < numsSize)
    {
        if (nums[src] == nums[src - 1])
        {
            src++;
        }
        else
        {
            nums[dest++] = nums[src++];
        }
    }

    return dest;
}

int main()
{
    int nums[] = { 0,0,1,1,1,2,2,3,3,4 };
    
    int ret = removeDuplicates(nums, 10);

    printf("%d, ", ret);
    printf("nums = [");

    for (int i = 0; i < ret; ++i)
    {
        printf("%d", nums[i]);
        
        if (i < ret - 1)
            printf(",");
    }

    printf("]");

    return 0;
}
