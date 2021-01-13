#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//���徲̬ջ
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
	int top;        //ջ��
	int capacity;   //����
}Stack;


//ջ�ĳ�ʼ��
void StackInit(Stack* S);

//����
void StackDestory(Stack* S);



//��ջ
void StackPush(Stack* S, ElementTypeData x);

//��ջ
void StackPop(Stack* S);

//��ȡ���ݵĸ���

int  StackSize(Stack* S);


//��ȡջ��������
ElementTypeData Stacktop(Stack* S);


int StackEmpty(Stack* S);



//ջ�ĳ�ʼ��
void StackInit(Stack* S)
{
	assert(S);
	S->a = malloc(sizeof(ElementTypeData)* 4);
	S->top = 0;
	S->capacity = 4;
}

//����
void StackDestory(Stack* S)
{
	assert(S);
	free(S->a);
	S->a = NULL;
	S->capacity = 0;
	S->top = 0;
}

//��ջ
void StackPush(Stack* S, ElementTypeData x)
{
	if (S->top == S->capacity)
	{
		S->capacity *= 2;
		ElementTypeData* p = (ElementTypeData*)realloc(S->a, sizeof(ElementTypeData)*S->capacity);
		if (p == NULL)
		{
			printf("�ڴ治��\n");
		}
		else
		{
			S->a = p;
		}
	}

	S->a[S->top] = x;
	S->top++;
}

//��ջ
void StackPop(Stack* S)
{
	assert(S);
	assert(S->top > 0);
	--S->top;
}

//��ȡ���ݵĸ���

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

//��ȡջ��������
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