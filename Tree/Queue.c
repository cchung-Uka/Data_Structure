#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);

	pq->phead = NULL;
	pq->ptail = NULL;
	pq->sz = 0;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("malloc failed!");
		return;
	}

	newnode->val = x;
	newnode->next = NULL;

	if (pq->ptail == NULL)
	{
		pq->phead = pq->ptail = newnode;
	}
	else
	{
		pq->ptail->next = newnode;
		pq->ptail = newnode;
	}

	pq->sz++;
}

void QueuePop(Queue* pq)
{
	assert(pq);

	assert(pq->phead);

	QNode* del = pq->phead;
	pq->phead = pq->phead->next;
	free(del);

	if (pq->phead == NULL)
		pq->ptail = NULL;

	pq->sz--;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);

	assert(pq->phead);

	return pq->phead->val;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);

	assert(pq->ptail);

	return pq->ptail->val;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->sz == 0;
}

int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->sz;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->phead;
	while (cur)
	{
		QNode* del = cur;
		cur = cur->next;
		free(del);
	}

	pq->phead = pq->ptail = NULL;
	pq->sz = 0;
}