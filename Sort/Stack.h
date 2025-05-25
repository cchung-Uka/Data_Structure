#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;

typedef struct Stack
{
	STDataType* data;
	int top;
	int capacity;
}ST;

void STInit(ST* pst);

void STPush(ST* pst, STDataType);

void STPop(ST* pst);

STDataType STTop(ST* pst);

bool STEmpty(ST* pst);

int STSize(ST* pst);

void STDestroy(ST* pst);