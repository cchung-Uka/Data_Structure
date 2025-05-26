#pragma once
#include <stdio.h>

void InsertSort(int* data, int sz);
void ShellSort(int* data, int sz);

void SelectSort(int* data, int sz);
void AdjustDown(int* data, int sz, int parent);
void HeapSort(int* data, int sz);

void BubbleSort(int* data, int sz);
void QuickSort_hoare(int* data, int begin, int end);
void QuickSort_hole(int* data, int begin, int end);
void QuickSort_ptr(int* data, int begin, int end);
void QuickSort(int* data, int begin, int end);
void QuickSortNonR(int* data, int begin, int end);

void MergeSort(int* data, int sz);
void MergeSortNonR(int* data, int sz);

void CountSort(int* data, int sz);

void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}