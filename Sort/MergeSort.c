#include <stdlib.h>
#include <string.h>

void Swap(int* p1, int* p2);

void _MergeSort(int* data, int begin, int end, int* tmp)
{
	if (begin >= end)
		return;

	int mid = (begin + end) / 2;

	_MergeSort(data, begin, mid, tmp);
	_MergeSort(data, mid + 1, end, tmp);

	int begin1 = begin, end1 = mid;
	int begin2 = mid + 1, end2 = end;
	
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (data[begin1] <= data[begin2])
		{
			tmp[i++] = data[begin1++];
		}
		else
		{
			tmp[i++] = data[begin2++];
		}
	}

	while (begin1 <= end1)
	{
		tmp[i++] = data[begin1++];
	}

	while (begin2 <= end2)
	{
		tmp[i++] = data[begin2++];
	}

	memcpy(data + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}

void MergeSort(int* data, int sz)
{
	int* tmp = (int*)malloc(sizeof(int) * sz);
	if (tmp == NULL)
	{
		perror("malloc failed!");
		return;
	}

	_MergeSort(data, 0, sz - 1, tmp);

	free(tmp);
	tmp = NULL;
}

void MergeSortNonR(int* data, int sz)
{
	int* tmp = (int*)malloc(sizeof(int) * sz);
	if (tmp == NULL)
	{
		perror("malloc failed!");
		return;
	}

	int gap = 1;
	while (gap < sz)
	{
		for (int i = 0; i < sz; i += 2 * gap)
		{
			int begin1 = i, end1 = i + gap - 1;
			int begin2 = i + gap, end2 = i + 2 * gap - 1;

			if (end1 >= sz || begin2 >= sz)
			{
				break;
			}
			
			if (end2 >= sz)
			{
				end2 = sz - 1;
			}

			int j = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (data[begin1] <= data[begin2])
				{
					tmp[j++] = data[begin1++];
				}
				else
				{
					tmp[j++] = data[begin2++];
				}
			}

			while (begin1 <= end1)
			{
				tmp[j++] = data[begin1++];
			}

			while (begin2 <= end2)
			{
				tmp[j++] = data[begin2++];
			}

			memcpy(data + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}

		gap *= 2;
	}

	free(tmp);
	tmp = NULL;
}
