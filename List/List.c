#define _CRT_SECURE_NO_WARNINGS 1

#include"List.h"

LTNode* CreateLTNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("malloc failed!\n");
		exit(-1);
	}

	newnode->val = x;
	newnode->next = NULL;
	newnode->prev = NULL;
	
	return newnode;
}

LTNode* LTInit()
{
	LTNode* phead = CreateLTNode(-1);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void LTPrint(LTNode* phead)
{
	assert(phead);

	printf("哨兵位<=>");

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->val);
		cur = cur->next;
	}

	printf("\n");
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	//LTNode* tail = phead->prev;
	//LTNode* newnode = CreateLTNode(x);

	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;

	LTInsert(phead, x);
}

void LTPopBack(LTNode* phead)
{
	assert(phead);

	// NULL
	assert(phead->next != phead);

	//LTNode* tail = phead->prev;
	//LTNode* tailPrev = tail->prev;

	//tailPrev->next = phead;
	//phead->prev = tailPrev;

	//free(tail);

	LTErase(phead->prev);
}

void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);

	//LTNode* newnode = CreateLTNode(x);

	//newnode->next = phead->next;
	//phead->next->prev = newnode;
	
	//phead->next = newnode;
	//newnode->prev = phead;

	LTInsert(phead->next, x);

}

void LTPopFront(LTNode* phead)
{
	assert(phead);

	// NULL
	assert(phead->next != phead);

	//LTNode* head = phead->next;
	//LTNode* headNext = head->next;

	//phead->next = headNext;
	//headNext->prev = phead;

	//free(head);

	LTErase(phead->next);
}

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->val == x) 
		{
			return cur;
		}

		cur = cur->next;
	}

	return NULL;
}

void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);

	LTNode* posPrev = pos->prev;
	LTNode* newnode = CreateLTNode(x);

	newnode->next = pos;
	pos->prev = newnode;

	newnode->prev = posPrev;
	posPrev->next = newnode;
}

void LTErase(LTNode* pos)
{
	assert(pos);

	LTNode* posNext = pos->next;
	LTNode* posPrev = pos->prev;

	posNext->prev = posPrev;
	posPrev->next = posNext;

	free(pos);
}

void LTDestroy(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* next = cur->next;

		free(cur);
		cur = next;
	}

	free(phead);
}
