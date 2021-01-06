#include<stdio.h>
#include<stdlib.h> 

#define stacksize 100

//定义顺序栈// 

typedef struct  
{
	ElementType elem[stacksize];  /*用来存放一维数组*/ 
	int top;
}Lstack;


//顺序栈的初始化// 
void Initstack(Lstack S) 
{
	S->top=-1;     /*构造一个空栈*/ 
}


bool Push(Lstack S,ElementType x)
{
	int i;
	if(S->top==stacksize-1)
	return(FALSE);//栈满// 
	S->top++;
	S->elem[S->top]=x;
	return(TRUE);
	
}


bool Pop(Lstack S,ElementType *temp)
{
	if(S->top==-1)
	return(FALSE);
	else
	{
	*temp=S->elem[S->top];
	S->top--;
	return(TRUE);
	}
}



int main()
{
	Lstack *S;
	char temp,ch;
	Initstack(S);
	printf("请输入字符列：");
	ch=getchar();
	while(ch!=&)
	{
	Push(S,ch);
	ch=getchar();	
	
	}
	do
	{
	ch=getchar();
	Pop(S,*temp);
	if(ch!=temp)
	{
		return(FALSE);
		printf("不是回文！"); 
	}
	}while(ch!=@ && S->top==-1)
	if(ch==@ && S->top==-1)
	{
		return(TRUE);
		printf("是回文"); 
		 
	}
	else{
		return(FALSE);
		printf("不是回文"); 
	}
	
	
}
