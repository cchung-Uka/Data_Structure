#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void PrintTopK(const char* file, int k)
{
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen failed!");
		return;
	}

	int* minHeap = (int*)malloc(sizeof(int) * k);
	if (minHeap == NULL)
	{
		perror("malloc failed!");
		return;
	}

	// ½¨Ð¡¶Ñ
	for (int i = 0; i < k; ++i)
	{
		fscanf(fout, "%d", &minHeap[i]);
		AdjustUp(minHeap, i);
	}

	int x = 0;
	while (fscanf(fout, "%d", &x) != EOF)
	{
		if (x > minHeap[0])
		{
			minHeap[0] = x;
			AdjustDown(minHeap, k, 0);
		}
	}

	for (int i = 0; i < k; ++i)
	{
		printf("%d ", minHeap[i]);
	}
	printf("\n");

	free(minHeap);

	fclose(fout);
}