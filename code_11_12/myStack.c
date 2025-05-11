#define _CRT_SECURE_NO_WARNINGS 1

typedef int QDataType;

typedef struct QueueNode
{
	QDataType val;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* phead;
	QNode* ptail;
	int sz;
}Queue;

void QueueInit(Queue* pq);

void QueuePush(Queue* pq, QDataType x);

void QueuePop(Queue* pq);

QDataType QueueFront(Queue* pq);

QDataType QueueBack(Queue* pq);

bool QueueEmpty(Queue* pq);

int QueueSize(Queue* pq);

void QueueDestroy(Queue* pq);

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

typedef struct
{
	Queue q1;
	Queue q2;
} MyStack;


MyStack* myStackCreate()
{
	MyStack* pst = (MyStack*)malloc(sizeof(MyStack));

	QueueInit(&pst->q1);
	QueueInit(&pst->q2);

	return pst;
}

void myStackPush(MyStack* obj, int x)
{
	if (!QueueEmpty(&obj->q1))
	{
		QueuePush(&obj->q1, x);
	}
	else
	{
		QueuePush(&obj->q2, x);
	}
}

int myStackPop(MyStack* obj)
{
	Queue* emptyq = &obj->q1;
	Queue* nonemptyq = &obj->q2;

	if (!QueueEmpty(&obj->q1))
	{
		emptyq = &obj->q2;
		nonemptyq = &obj->q1;
	}

	while (QueueSize(nonemptyq) > 1)
	{
		QueuePush(emptyq, QueueFront(nonemptyq));
		QueuePop(nonemptyq);
	}

	int top = QueueBack(nonemptyq);
	QueuePop(nonemptyq);

	return top;

}

int myStackTop(MyStack* obj)
{
	if (!QueueEmpty(&obj->q1))
	{
		return QueueBack(&obj->q1);
	}
	else
	{
		return QueueBack(&obj->q2);
	}
}

bool myStackEmpty(MyStack* obj) 
{
	return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) 
{
	QueueDestroy(&obj->q1);
	QueueDestroy(&obj->q2);

	free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);

 * int param_2 = myStackPop(obj);

 * int param_3 = myStackTop(obj);

 * bool param_4 = myStackEmpty(obj);

 * myStackFree(obj);
*/