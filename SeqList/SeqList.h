#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int SLDataType;

// sequence list
typedef struct SeqList
{
	SLDataType* data;
	int sz;
	int capacity;
}SL;

void SLInit(SL* psl);

void SLCheckCapacity(SL* psl);

void SLPushBack(SL* psl, SLDataType x);

void SLPopBack(SL* psl);

void SLPushFront(SL* psl, SLDataType x);

void SLPopFront(SL* psl);

int SLFind(SL* psl, SLDataType x);

void SLInsert(SL* psl, int pos, SLDataType x);

void SLErase(SL* psl, int pos);

void SLDestroy(SL* psl);

void SLPrint(SL* psl);
