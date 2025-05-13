#include "Heap.h"

void HeapSort(int* data, int sz)
{
	// O(N*logN)
	/*for (int i = 0; i < sz; i++)
	{
		AdjustUp(data, i);
	}*/

	// O(N)
	for (int i = (sz - 1 - 1) / 2; i >= 0; --i)
	{
		AdjustDown(data, sz, i);
	}

	int end = sz - 1;
	while (end > 0)
	{
		Swap(&data[0], &data[end]);
		AdjustDown(data, end, 0);
		--end;
	}
}