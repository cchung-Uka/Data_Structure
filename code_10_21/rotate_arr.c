#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//void reverse(int* left, int* right)
//{
//    while (left < right)
//    {
//        int tmp = *left;
//        *left = *right;
//        *right = tmp;
//        left++;
//        right--;
//    }
//}

//void rotate(int* nums, int numsSize, int k)
//{
//    k %= numsSize;
//
//    reverse(nums, nums + numsSize - 1 - k);
//    reverse(nums + numsSize - k, nums + numsSize - 1);
//    reverse(nums, nums + numsSize - 1);
//}

void rotate(int* nums, int numsSize, int k)
{
    int* newNums = (int*)calloc(numsSize, sizeof(int));

    if (newNums == NULL)
    {
        perror("malloc->");
        exit(1);
    }

    for (int i = 0; i < numsSize; ++i)
    {
        //将原数组下标为 i 的元素放至新数组下标为 (i+k) mod numsSize 的位置
        newNums[(i + k) % numsSize] = nums[i];
    }

    for (int i = 0; i < numsSize; ++i)
    {
        nums[i] = newNums[i];
    }

    free(newNums);
    newNums = NULL;
}