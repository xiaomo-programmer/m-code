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
		printf("����ռ�ʧ��\n");
		exit(-1);
	}
	memset(L->a, 0, sizeof(L->a));
}


//����
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
			printf("����ʧ��\n");
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
		printf("�ռ䲻��");
			return;
	}
	checkcapacity(L);
	printf("1.��������ϵ��������");
	scanf("%s", &L->a[L->size].name);
	printf("\n");
	printf("2.��������ϵ�˵绰��");
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
		printf("���޴���\n");
		return -1;
	}
	printf("������Ҫ���ҵ���ϵ��������");
	scanf("%s", &name);
	for (i = 0; i < L->size; i++)
	{
		if (strcmp(name, L->a[i].name) == 0)
		{
			printf("������%s\n", L->a[i].name);
			printf("�绰���룺%s\n",L->a[i].tel );
			return i;
		}
	}
	printf("���޴���\n");
	return -1;
}




void adListDelete(addList L)
{
	assert(L);
	int i = 0;
	int num = 0;
	if (L->size == 0)
	{
		printf("���޴���\n");
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
	printf("ɾ���ɹ�\n");
	L->size--;
}



void adListchange(addList L)
{
	assert(L);
	int i = 0;
	if (L->size == 0)
	{
		printf("���޴���\n");
		return -1;
	}
	
	
		i = adListFind(L);
		if (i != -1)
		{
			printf("�������޸ĺ��������");
			scanf("%s", &L->a[i].name);
			printf("\n");
			printf("�������޸ĺ�ĵ绰���룺");
			scanf("%s", &L->a[i].tel);
			printf("�޸ĳɹ�\n");

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
		printf("���޴���\n");
		return -1;
	}
	for (i = 0; i < L->size; i++)
	{
		printf("������%s���绰���룺%s", L->a[i].name, L->a[i].tel);
		printf("\n");
	}
}