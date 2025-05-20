void Swap(int* p1, int* p2);

void SelectSort(int* data, int sz)
{
	int begin = 0;
	int end = sz - 1;

	while (begin < end)
	{
		int mini = begin, maxi = begin;

		for (int i = begin + 1; i <= end; ++i)
		{
			if (data[i] < data[mini])
			{
				mini = i;
			}
			
			if (data[i] > data[maxi])
			{
				maxi = i;
			}
		}

		Swap(&data[begin], &data[mini]);

		if (maxi == begin)
		{
			maxi = mini;
		}
		Swap(&data[end], &data[maxi]);

		++begin;
		--end;
	}
}