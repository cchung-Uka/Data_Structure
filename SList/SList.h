#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType val;
	struct SListNode* next;
}SLNode;

void SLTPushBack(SLNode** pphead, SLTDataType x);

void SLTPushFront(SLNode** pphead, SLTDataType x);

void SLTPopBack(SLNode** pphead);

void SLTPopFront(SLNode** pphead);

SLNode* SLTFind(SLNode* phead, SLTDataType x);

void SLTInsertAfter(SLNode* pos, SLTDataType x);

void SLTEraseAfter(SLNode* pos);

//在pos的前面插入
void SLTInsert(SLNode** pphead, SLNode* pos, SLTDataType x);

//删除pos位置
void SLTErase(SLNode** pphead, SLNode* pos);

void SLTDestroy(SLNode** pphead);

void SLTPrint(SLNode* phead);