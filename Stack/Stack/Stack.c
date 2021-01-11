#include"stack.h"








//栈的初始化
void StackInit(Stack* S)
{
	assert(S);
	S->a = malloc(sizeof(ElementTypeData)* 4);
	S->top = 0;
	S->capacity = 4;
}

//销毁
void StackDestory(Stack* S)
{
	assert(S);
	free(S->a);
	S->a = NULL;
	S->capacity = 0;
	S->top = 0;
}

//入栈
void StackPush(Stack* S,ElementTypeData x)
{
	if (S->top == S->capacity)
	{
		S->capacity *= 2;
		ElementTypeData* p = (ElementTypeData*)realloc(S->a, sizeof(ElementTypeData)*S->capacity);
		if (p == NULL)
		{
			printf("内存不足\n");
		}
		else
		{
			S->a = p;
		}
	}

	S->a[S->top] = x;
	S->top++;
}

//出栈
void StackPop(Stack* S)
{
	assert(S);
	assert(S->top > 0);
	--S->top;
}

//获取数据的个数

int  StackSize(Stack* S)
{
	assert(S);
	return S->top;
}


int StackEmpty(Stack* S)
{
	assert(S);
	return S->top == 0 ? 1:0;
}

//获取栈顶的数据
ElementTypeData Stacktop(Stack* S)
{
	assert(S);
	assert(S->top > 0);

	return S->a[S->top -1];
}






