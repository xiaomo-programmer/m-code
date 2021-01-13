#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//定义静态栈
//#define N 10
typedef int ElementTypeData;
//typedef struct Stack
//{
//	ElementTypeData a[N];
//	int top;
//}Stack;



typedef struct Stack
{
	ElementTypeData* a;
	int top;        //栈顶
	int capacity;   //容量
}Stack;


//栈的初始化
void StackInit(Stack* S);

//销毁
void StackDestory(Stack* S);



//入栈
void StackPush(Stack* S, ElementTypeData x);

//出栈
void StackPop(Stack* S);

//获取数据的个数

int  StackSize(Stack* S);


//获取栈顶的数据
ElementTypeData Stacktop(Stack* S);


int StackEmpty(Stack* S);



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
void StackPush(Stack* S, ElementTypeData x)
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
	return S->top == 0 ? 1 : 0;
}

//获取栈顶的数据
ElementTypeData Stacktop(Stack* S)
{
	assert(S);
	assert(S->top > 0);

	return S->a[S->top - 1];
}






















typedef struct {
	Stack S1;
	Stack S2;

} MyQueue;

/** Initialize your data structure here. */

MyQueue* myQueueCreate() {
	MyQueue* S = (MyQueue*)malloc(sizeof(MyQueue));
	StackInit(&S->S1);
	StackInit(&S->S2);

	return S;

}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	StackPush(&obj->S1, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	int front = myQueuePeek(obj);
	StackPop(&obj->S2);
	return front;

}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (!StackEmpty(&obj->S2))
	{
		return Stacktop(&obj->S2);
	}
	else
	{
		while (!StackEmpty(&obj->S1))
		{
			StackPush(&obj->S2, Stacktop(&obj->S1));
			StackPop(&obj->S1);
		}
		return Stacktop(&obj->S2);
	}

}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return StackEmpty(&obj->S1) && StackEmpty(&obj->S2);
}

void myQueueFree(MyQueue* obj) {

}