#define _CRT_SECURE_NO_WARNINGS 1

#include"SList.h"

SLNode* CreatNode(SLTDataType x)
{
	SLNode* newnode = (SLNode*)malloc(sizeof(SLNode));
	if (newnode == NULL)
	{
		perror("malloc failed!");
		exit(-1);
	}

	newnode->val = x;
	newnode->next = NULL;

	return newnode;
}

void SLTPushBack(SLNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLNode* newnode = CreatNode(x);

	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		SLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}

		tail->next = newnode;
	}
}

void SLTPushFront(SLNode** pphead, SLTDataType x)
{
	assert(pphead);

	SLNode* newnode = CreatNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPopBack(SLNode** pphead)
{
	assert(pphead);

	// 空
	assert(*pphead);

	// 1.一个结点
	// 2.多个结点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		SLNode* prev = NULL;
		SLNode* tail = *pphead;

		// 找尾
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}

		free(tail);
		tail = NULL;

		prev->next = NULL;

		/*SLNode* tail = *pphead;
		while (tail->next->next != NULL)
		{
			tail = tail->next;
		}

		free(tail->next);
		tail->next = NULL;*/
	}
}

void SLTPopFront(SLNode** pphead)
{
	assert(pphead && *pphead);

	SLNode* next = (*pphead)->next;
	free(*pphead);
	*pphead = next;
}

SLNode* SLTFind(SLNode* phead, SLTDataType x)
{
	SLNode* cur = phead;
	while (cur)
	{
		if (cur->val == x)
		{
			return cur;
		}
		cur = cur->next;
	}

	return NULL;
}

void SLTInsertAfter(SLNode* pos, SLTDataType x)
{
	assert(pos);

	SLNode* newnode = CreatNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SLTEraseAfter(SLNode* pos)
{
	assert(pos && pos->next);
	
	SLNode* next = pos->next;
	pos->next = pos->next->next;

	free(next);
	next = NULL;
}

void SLTInsert(SLNode** pphead, SLNode* pos, SLTDataType x)
{
	// 严格规定pos一定是链表里面的一个有效结点
	assert(pphead);
	assert(*pphead);
	assert(pos);

	// 头插
	if (*pphead == pos)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		SLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}

		SLNode* newnode = CreatNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}

void SLTErase(SLNode** pphead, SLNode* pos)
{
	assert(pphead);
	assert(*pphead);
	assert(pos);

	// 头删
	if (*pphead == pos)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLNode* prev = *pphead;
		while (prev->next != pos);
		{
			prev = prev->next;
		}

		prev->next = pos->next;
		free(pos);
		pos = NULL;
	}
}

void SLTDestroy(SLNode** pphead)
{
	assert(pphead && *pphead);

	SLNode* cur = *pphead;
	while (cur)
	{
		SLNode* next = cur->next;
		free(cur);
		cur = next;
	}

	*pphead = NULL;
}

void SLTPrint(SLNode* phead)
{
	SLNode* cur = phead;
	while (cur)
	{
		printf("%d->", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}