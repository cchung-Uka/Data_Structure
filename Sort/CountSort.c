#include <stdlib.h>

void CountSort(int* data, int sz)
{
	int min = data[0], max = data[0];
	for (int i = 0; i < sz; ++i)
	{
		if (data[i] < min)
			min = data[i];
		
		if (data[i] > max)
			max = data[i];
	}

	int range = max - min + 1;
	int* count = (int*)calloc(range, sizeof(int));
	if (count == NULL)
	{
		perror("calloc failed!");
		return;
	}

	for (int i = 0; i < sz; ++i)
	{
		count[data[i] - min]++;
	}

	int i = 0;
	for (int j = 0; j < range; ++j)
	{
		while (count[j]--)
		{
			data[i++] = j + min;
		}
	}

	free(count);
	count = NULL;
}