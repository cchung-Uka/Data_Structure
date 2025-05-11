#define _CRT_SECURE_NO_WARNINGS 1

typedef char STDataType;

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

bool isValid(char* s)
{
	ST st;
	STInit(&st);

	while (*s)
	{
		if (*s == '(' || *s == '[' || *s == '{')
		{
			STPush(&st, *s);
		}
		else
		{
			// 右括号多，左括号少，或者第一个就是右括号
			if (STEmpty(&st))
			{
				STDestroy(&st);
				return false;
			}

			char top = STTop(&st);
			STPop(&st);

			if ((top == '(' && *s != ')')
				|| (top == '[' && *s != ']')
				|| (top == '{' && *s != '}'))
			{
				STDestroy(&st);
				return false;
			}
		}

		++s;
	}

	// 栈为空，数量匹配；栈不为空，左括号多，右括号少
	bool ret = STEmpty(&st);

	STDestroy(&st);

	return ret;
}