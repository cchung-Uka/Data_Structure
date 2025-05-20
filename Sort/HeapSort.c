void Swap(int* p1, int* p2);

void AdjustDown(int* data, int sz, int parent)
{
	int child = parent * 2 + 1;

	while (child < sz)
	{
		if (child + 1 < sz && data[child + 1] > data[child])
		{
			++child;
		}

		if (data[child] > data[parent])
		{
			Swap(&data[child], &data[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}

// 升序
void HeapSort(int* data, int sz)
{
	// 建大堆
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
