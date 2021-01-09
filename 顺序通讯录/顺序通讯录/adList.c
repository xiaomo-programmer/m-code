#define _CRT_SECURE_NO_WARNINGS

#include"addressList.h"


void adListInit(addList L)
{   
	assert(L);
	L->size = 0;
	L->capacity = 4;
	L->a = (nName)malloc((L->capacity)*sizeof(Name));
	if (L->a == NULL)
	{
		printf("申请空间失败\n");
		exit(-1);
	}
	memset(L->a, 0, sizeof(L->a));
}


//扩容
void checkcapacity(addList L)
{
	assert(L);
	addList* newNode = NULL;
	L->capacity *= 2;
	if (L->size == L->capacity)
	{
		newNode = (nName)realloc(L->a,(L->capacity)*sizeof(Name));

		if (newNode == NULL)
		{
			printf("扩容失败\n");
			exit(-1);
		}
		else
		{
			L->a = newNode;
		}

	}
}


void adListadd(addList L)
{
	
	assert(L);
	if (L->size == MAX)
	{
		printf("空间不足");
			return;
	}
	checkcapacity(L);
	printf("1.请输入联系人姓名：");
	scanf("%s", &L->a[L->size].name);
	printf("\n");
	printf("2.请输入联系人电话：");
	scanf("%s", &L->a[L->size].tel);
	L->size++;

}


int  adListFind(addList L)
{
	assert(L);
	char name[MAX];
	int i = 0;
	if (0 == L->size)
	{
		printf("查无此人\n");
		return -1;
	}
	printf("请输入要查找的联系人姓名：");
	scanf("%s", &name);
	for (i = 0; i < L->size; i++)
	{
		if (strcmp(name, L->a[i].name) == 0)
		{
			printf("姓名：%s\n", L->a[i].name);
			printf("电话号码：%s\n",L->a[i].tel );
			return i;
		}
	}
	printf("查无此人\n");
	return -1;
}




void adListDelete(addList L)
{
	assert(L);
	int i = 0;
	int num = 0;
	if (L->size == 0)
	{
		printf("查无此人\n");
		return -1;
	}
	num = adListFind(L);
	if (num != -1)
	{
		for (i = num; i < L->size; i++)
		{
			L->a[i] = L->a[i + 1];
		}
	}
	printf("删除成功\n");
	L->size--;
}



void adListchange(addList L)
{
	assert(L);
	int i = 0;
	if (L->size == 0)
	{
		printf("查无此人\n");
		return -1;
	}
	
	
		i = adListFind(L);
		if (i != -1)
		{
			printf("请输入修改后的姓名：");
			scanf("%s", &L->a[i].name);
			printf("\n");
			printf("请输入修改后的电话号码：");
			scanf("%s", &L->a[i].tel);
			printf("修改成功\n");

		}
		else
		{
			return;
		}
	
}



void adListshow(addList L)
{
	assert(L);
	int i = 0;
	if (L->size == 0)
	{
		printf("查无此人\n");
		return -1;
	}
	for (i = 0; i < L->size; i++)
	{
		printf("姓名：%s，电话号码：%s", L->a[i].name, L->a[i].tel);
		printf("\n");
	}
}