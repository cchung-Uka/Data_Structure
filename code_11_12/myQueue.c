#define _CRT_SECURE_NO_WARNINGS 1

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
			perror("malloc failed!");
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

typedef struct 
{
	ST pushst;
	ST popst;
} MyQueue;


MyQueue* myQueueCreate() 
{
	MyQueue* pq = (MyQueue*)malloc(sizeof(MyQueue));

	STInit(&pq->pushst);
	STInit(&pq->popst);

	return pq;
}

void myQueuePush(MyQueue* obj, int x) {
	STPush(&obj->pushst, x);
}

int myQueuePop(MyQueue* obj) {
	int front = myQueuePeek(obj);
	STPop(&obj->popst);

	return front;
}

int myQueuePeek(MyQueue* obj) {
	if (STEmpty(&obj->popst))
	{
		while (!STEmpty(&obj->pushst))
		{
			STPush(&obj->popst, STTop(&obj->pushst));
			STPop(&obj->pushst);
		}
	}

	return STTop(&obj->popst);
}

bool myQueueEmpty(MyQueue* obj) {
	return STEmpty(&obj->pushst) && STEmpty(&obj->popst);
}

void myQueueFree(MyQueue* obj) {
	STDestroy(&obj->pushst);
	STDestroy(&obj->popst);

	free(obj);
}

/**
 * Your MyQueue struct will be instantiated and called as such:
 * MyQueue* obj = myQueueCreate();
 * myQueuePush(obj, x);

 * int param_2 = myQueuePop(obj);

 * int param_3 = myQueuePeek(obj);

 * bool param_4 = myQueueEmpty(obj);

 * myQueueFree(obj);
*/