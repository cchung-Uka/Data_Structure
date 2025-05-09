#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef int LTDataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	LTDataType val;
}LTNode;

LTNode* LTInit();

void LTPrint(LTNode* phead);

void LTPushBack(LTNode* phead, LTDataType x);

void LTPopBack(LTNode* phead);

void LTPushFront(LTNode* phead, LTDataType x);

void LTPopFront(LTNode* phead);

LTNode* LTFind(LTNode* phead, LTDataType x);

// 在pos的前面插入
void LTInsert(LTNode* pos, LTDataType x);

// 删除pos位置
void LTErase(LTNode* pos);

void LTDestroy(LTNode* phead);
