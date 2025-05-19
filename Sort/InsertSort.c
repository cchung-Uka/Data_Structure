void InsertSort(int* data, int sz)
{
	for (int i = 0; i < sz - 1; ++i)
	{
		int end = i;
		int key = data[end + 1];
		while (end >= 0)
		{
			if (key < data[end])
			{
				data[end + 1] = data[end];
				--end;
			}
			else
			{
				break;
			}
		}

		data[end + 1] = key;
	}
}