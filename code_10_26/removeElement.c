#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>

int removeElement(int* nums, int numsSize, int val)
{
    assert(nums);

    int src = 0;
    int dest = 0;

    while (src < numsSize)
    {
        if (nums[src] != val)
        {
            nums[dest++] = nums[src++];
        }
        else
        {
            src++;
        }
    }

    return dest;
}

int main()
{
    int nums[] = { 0,1,2,2,3,0,4,2 };
    int val = 2;

    int sz = sizeof(nums) / sizeof(int);
    int ret = removeElement(nums, sz, val);

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
