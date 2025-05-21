void Swap(int* p1, int* p2);

void BubbleSort(int* data, int sz)
{
	for (int j = 0; j < sz - 1; ++j)
	{
		int exchange = 0;
		for (int i = 1; i < sz - j; ++i)
		{
			if (data[i - 1] > data[i])
			{
				Swap(&data[i - 1], &data[i]);
				exchange = 1;
			}
		}

		if (exchange == 0)
			break;
	}
}