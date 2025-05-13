#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;

typedef struct Heap
{
	HPDataType* data;
	int sz;
	int capacity;
}HP;

void HeapInit(HP* php);

void HeapDestroy(HP* php);

void Swap(HPDataType* p1, HPDataType* p2);

void AdjustUp(HPDataType* data, int child);

void AdjustDown(HPDataType* data, int sz, int parent);

void HeapPush(HP* php, HPDataType x);

void HeapPop(HP* php);

HPDataType HeapTop(HP* php);

size_t HeapSize(HP* php);

bool HeapEmpty(HP* php);
