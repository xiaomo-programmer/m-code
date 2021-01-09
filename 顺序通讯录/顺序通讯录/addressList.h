#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<string.h>



#define MAX 20


typedef int ElementTypeData;

typedef struct Name
{
	char name[MAX];
	char tel[11];
}Name, *nName;



typedef struct adList
{
	nName a;
	int size;
	int capacity;
}adList,*addList;

//初始化通讯录
void adListInit(addList L);


//扩容
void checkcapacity(addList L);


//添加联系人
void adListadd(addList L);


//查找联系人
int adListFind(addList L);

//删除联系人

void adListDelete(addList L);

//修改联系人

void adListchange(addList L);


//打印联系人
void adListshow(addList L);