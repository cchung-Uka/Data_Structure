#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void SLInit(SL* psl)
{
	assert(psl);

	psl->data = NULL;
	psl->sz = 0;
	psl->capacity = 0;
}

void SLCheckCapacity(SL* psl)
{
	assert(psl);

	if (psl->sz == psl->capacity)
	{
		int newCapacity = psl->capacity == 0 ? 4 : psl->capacity * 2;
		SLDataType* tmp = (SLDataType*)realloc(psl->data, sizeof(SLDataType) * newCapacity);
		if (tmp == NULL)
		{
			perror("realloc failed!");
			return;
		}

		psl->data = tmp;
		psl->capacity = newCapacity;
	}
}

void SLPushBack(SL* psl, SLDataType x)
{
	assert(psl);

	SLCheckCapacity(psl);

	psl->data[psl->sz] = x;
	psl->sz++;
}

void SLPopBack(SL* psl)
{
	assert(psl);
	assert(psl->sz > 0);

	psl->sz--;
}

void SLPushFront(SL* psl, SLDataType x)
{
	assert(psl);

	SLCheckCapacity(psl);

	int end = psl->sz - 1;
	while (end >= 0)
	{
		psl->data[end + 1] = psl->data[end];
		--end;
	}

	psl->data[0] = x;
	psl->sz++;
}

void SLPopFront(SL* psl)
{
	assert(psl);
	assert(psl->sz > 0);

	int begin = 0;
	while (begin < psl->sz - 1)
	{
		psl->data[begin] = psl->data[begin + 1];
		++begin;
	}

	psl->sz--;
}

int SLFind(SL* psl, SLDataType x)
{
	assert(psl);

	for (int i = 0; i < psl->sz; ++i)
	{
		if (psl->data[i] == x)
		{
			return i;
		}
	}

	return -1;
}

void SLInsert(SL* psl, int pos, SLDataType x)
{
	assert(psl);
	assert(pos >= 0 && pos <= psl->sz);

	SLCheckCapacity(psl);

	int end = psl->sz;
	while (end > pos)
	{
		psl->data[end] = psl->data[end - 1];
		--end;
	}

	psl->data[pos] = x;
	psl->sz++;
}

void SLErase(SL* psl, int pos)
{
	assert(psl);
	assert(pos >= 0 && pos < psl->sz);
	
	int begin = pos;
	while (begin < psl->sz - 1)
	{
		psl->data[begin] = psl->data[begin + 1];
		++begin;
	}

	psl->sz--;
}

void SLDestroy(SL* psl)
{
	assert(psl);

	if (psl->data != NULL)
	{
		free(psl->data);
		psl->data = NULL;

		psl->capacity = 0;
		psl->sz = 0;
	}
}

void SLPrint(SL* psl)
{
	assert(psl);

	for (int i = 0; i < psl->sz; ++i)
	{
		printf("%d ", psl->data[i]);
	}

	printf("\n");
}