#include<stdio.h>
#include<stdlib.h> 

#define stacksize 100

//����˳��ջ// 

typedef struct  
{
	ElementType elem[stacksize];  /*�������һά����*/ 
	int top;
}Lstack;


//˳��ջ�ĳ�ʼ��// 
void Initstack(Lstack S) 
{
	S->top=-1;     /*����һ����ջ*/ 
}


bool Push(Lstack S,ElementType x)
{
	int i;
	if(S->top==stacksize-1)
	return(FALSE);//ջ��// 
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
	printf("�������ַ��У�");
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
		printf("���ǻ��ģ�"); 
	}
	}while(ch!=@ && S->top==-1)
	if(ch==@ && S->top==-1)
	{
		return(TRUE);
		printf("�ǻ���"); 
		 
	}
	else{
		return(FALSE);
		printf("���ǻ���"); 
	}
	
	
}
