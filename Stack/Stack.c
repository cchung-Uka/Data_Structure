#define _CRT_SECURE_NO_WARNINGS 1

#include "Stack.h"

void STInit(ST* pst)
{
	assert(pst);

	pst->data = NULL;
	
	pst->capacity = 0;
	pst->top = 0;
}

void STPush(ST* pst, STDataType x)
{
	assert(pst);

	if (pst->top == pst->capacity)
	{
		int newcapacity = pst->capacity == 0 ? 4 : pst->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(pst->data, sizeof(STDataType) * newcapacity);
		if (tmp == NULL)
		{
			perror("realloc failed!");
			return;
		}

		pst->data = tmp;
		pst->capacity = newcapacity;
	}

	pst->data[pst->top] = x;
	pst->top++;
}

void STPop(ST* pst)
{
	assert(pst);

	assert(pst->top > 0);

	pst->top--;
}

STDataType STTop(ST* pst)
{
	assert(pst);

	assert(pst->top > 0);

	return pst->data[pst->top - 1];
}

bool STEmpty(ST* pst)
{
	assert(pst);

	return pst->top == 0;
}

int STSize(ST* pst)
{
	assert(pst);

	return pst->top;
}

void STDestroy(ST* pst)
{
	assert(pst);

	free(pst->data);
	pst->data = NULL;

	pst->capacity = 0;
	pst->top = 0;
}