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