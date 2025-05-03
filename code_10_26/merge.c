#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

//˫ָ
//void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
//{
//    assert(nums1 && nums2);
//
//    int* parr = calloc(m + n, (m + n) * sizeof(int));
//    if (parr == NULL)
//    {
//        return;
//    }
//
//    int i = 0;
//    int j = 0;
//    int k = 0;
//
//    while (i < m && j < n)
//    {
//        if (nums1[i] < nums2[j])
//        {
//            parr[k++] = nums1[i++];
//        }
//        else
//        {
//            parr[k++] = nums2[j++];
//        }
//    }
//
//    if (i == m)
//    {
//        while (j < n)
//        {
//            parr[k++] = nums2[j++];
//        }
//    }
//
//    if (j == n)
//    {
//        while (i < m)
//        {
//            parr[k++] = nums1[i++];
//        }
//    }
//
//    for (i = 0; i < m + n; i++)
//    {
//        nums1[i] = parr[i];
//    }
//
//    free(parr);
//    parr = NULL;
//}

//˫ָ
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n)
{
    assert(nums1 && nums2);

    int p1 = m - 1;
    int p2 = n - 1;
    int index = m + n - 1;

    while (p1 > -1 && p2 > -1)
    {
        if (nums1[p1] > nums2[p2])
        {
            nums1[index--] = nums1[p1--];
        }
        else
        {
            nums1[index--] = nums2[p2--];
        }
    }

    while (p2 > -1)
    {
        nums1[index--] = nums2[p2--];
    }
}

int main()
{
    int nums1[] = { 1,2,3,0,0,0 };
    int nums2[] = { 2,5,6 };

    int sz1 = sizeof(nums1) / sizeof(int);
    int sz2 = sizeof(nums2) / sizeof(int);

    merge(nums1, sz1, sz1 - sz2, nums2, sz2, sz2);

    printf("[");

    for (int i = 0; i < sz1; ++i)
    {
        printf("%d", nums1[i]);
        if (i < sz1 - 1)
            printf(",");
    }

    printf("]");

    return 0;
}
