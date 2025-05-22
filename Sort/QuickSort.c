#include "Stack.h"

void Swap(int* p1, int* p2);

// 三数取中
int Get_midi(int* data, int begin, int end)
{
	int midi = (begin + end) / 2;

	if (data[begin] < data[midi])
	{
		if (data[midi] < data[end])
			return midi;
		else if (data[begin] > data[end])
			return begin;
		else
			return end;
	}
	else
	{
		if (data[midi] > data[end])
			return midi;
		else if (data[begin] < data[end])
			return begin;
		else
			return end;
	}
}

void QuickSort_hoare(int* data, int begin, int end)
{
	if (begin >= end)
		return;

	int left = begin, right = end;
	int keyi = begin;

	while (left < right)
	{
		while (left < right && data[right] >= data[keyi])
		{
			--right;
		}

		while (left < right && data[left] <= data[keyi])
		{
			++left;
		}

		Swap(&data[left], &data[right]);
	}

	Swap(&data[left], &data[keyi]);
	keyi = left;

	QuickSort_hoare(data, begin, keyi - 1);
	QuickSort_hoare(data, keyi + 1, end);
}

void QuickSort_hole(int* data, int begin, int end)
{
	if (begin >= end)
		return;

	int left = begin, right = end;
	int key = data[begin], hole = begin;

	while (left < right)
	{
		while (left < right && data[right] >= key)
		{
			--right;
		}

		data[hole] = data[right];
		hole = right;

		while (left < right && data[left] <= key)
		{
			++left;
		}

		data[hole] = data[left];
		hole = left;
	}

	data[hole] = key;

	QuickSort_hole(data, begin, hole - 1);
	QuickSort_hole(data, hole + 1, end);
}

void QuickSort_ptr(int* data, int begin, int end)
{
	if (begin >= end)
		return;

	int prev = begin, cur = begin + 1;
	int keyi = begin;

	while (cur <= end)
	{
		if (data[cur] < data[keyi] && ++prev != cur)
		{
			Swap(&data[prev], &data[cur]);
		}
		++cur;
	}

	Swap(&data[prev], &data[keyi]);
	keyi = prev;

	QuickSort_ptr(data, begin, keyi - 1);
	QuickSort_ptr(data, keyi + 1, end);
}

int PartSort(int* data, int begin, int end)
{
	int prev = begin, cur = begin + 1;
	int keyi = begin;

	while (cur <= end)
	{
		if (data[cur] < data[keyi] && ++prev != cur)
		{
			Swap(&data[prev], &data[cur]);
		}
		++cur;
	}

	Swap(&data[prev], &data[keyi]);
	return prev;
}

void QuickSort(int* data, int begin, int end)
{
	if (begin >= end)
		return;

	int keyi = PartSort(data, begin, end);
	QuickSort(data, begin, keyi - 1);
	QuickSort(data, keyi + 1, end);
}

void QuickSortNonR(int* data, int begin, int end)
{
	ST st;
	STInit(&st);
	STPush(&st, end);
	STPush(&st, begin);

	while (!STEmpty(&st))
	{
		int left = STTop(&st);
		STPop(&st);
		int right = STTop(&st);
		STPop(&st);

		int keyi = PartSort(data, left, right);
		
		if (left < keyi - 1)
		{
			STPush(&st, keyi - 1);
			STPush(&st, left);
		}

		if (keyi + 1 < right)
		{
			STPush(&st, right);
			STPush(&st, keyi + 1);
		}
	}

	STDestroy(&st);
}