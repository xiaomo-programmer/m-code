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