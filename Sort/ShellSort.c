void ShellSort(int* data, int sz)
{
	int gap = sz;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		
		// 多组并排
		for (int i = 0; i < sz - gap; ++i)
		{
			int end = i;
			int key = data[end + gap];
			while (end >= 0)
			{
				if (key < data[end])
				{
					data[end + gap] = data[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}

			data[end + gap] = key;
		}
	}
}

//void ShellSort(int* data, int sz)
//{
//	int gap = sz;
//	while (gap > 1)
//	{
//		gap = gap / 3 + 1;

//		// 一组一组排
//		for (int j = 0; j < gap; ++j)
//		{
//			for (int i = j; i < sz - gap; i += gap)
//			{
//				int end = i;
//				int key = data[end + gap];
//				while (end >= 0)
//				{
//					if (key < data[end])
//					{
//						data[end + gap] = data[end];
//						end -= gap;
//					}
//					else
//					{
//						break;
//					}
//				}
//
//				data[end + gap] = key;
//			}
//		}
//	}
//}