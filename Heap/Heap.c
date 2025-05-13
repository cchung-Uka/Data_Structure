#define _CRT_SECURE_NO_WARNINGS 1

#include "Heap.h"

void HeapInit(HP* php)
{
	assert(php);

	php->data = NULL;
	php->sz = 0;
	php->capacity = 0;
}

void HeapDestroy(HP* php)
{
	assert(php);

	free(php->data);
	php->data = NULL;
	php->sz = php->capacity = 0;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}

void AdjustUp(HPDataType* data, int child)
{
	int parent = (child - 1) / 2;

	while (child > 0)
	{
		if (data[child] < data[parent])
		{
			Swap(&data[child], &data[parent]);

			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);

	int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
	if (php->sz == php->capacity)
	{
		HPDataType* tmp = (HPDataType*)realloc(php->data, sizeof(HPDataType) * newCapacity);
		if (tmp == NULL)
		{
			perror("malloc failed!");
			exit(-1);
		}

		php->data = tmp;
		php->capacity = newCapacity;	
	}

	php->data[php->sz] = x;

	AdjustUp(php->data, php->sz);

	php->sz++;
}

void AdjustDown(HPDataType* data, int sz, int parent)
{
	int child = parent * 2 + 1;

	while (child < sz)
	{
		if (child + 1 < sz && data[child + 1] < data[child])
		{
			++child;
		}
		
		if (data[child] < data[parent])
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

void HeapPop(HP* php)
{
	assert(php);
	assert(php->sz > 0);

	Swap(&php->data[0], &php->data[php->sz - 1]);
	php->sz--;

	AdjustDown(php->data, php->sz, 0);
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	assert(php->sz > 0);

	return php->data[0];
}

size_t HeapSize(HP* php)
{
	assert(php);

	return php->sz;
}

bool HeapEmpty(HP* php)
{
	assert(php);

	return php->sz == 0;
}
