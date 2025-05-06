#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//int missingNumber(int* nums, int numsSize)
//{
//    int xor = 0;
//
//    for (int i = 0; i < numsSize; ++i)
//    {
//        xor ^= nums[i];
//    }
//
//    for (int i = 0; i <= numsSize; ++i)
//    {
//        xor ^= i;
//    }
//
//    return xor;
//}

int missingNumber(int* nums, int numsSize)
{
    int N = numsSize;
    int sum = (0 + N) * (numsSize + 1) / 2;//等差数列求和

    for (int i = 0; i < numsSize; ++i)
    {
        sum -= nums[i];//减掉原数组的值，剩下的就是消失的数据
    }

    return sum;
}