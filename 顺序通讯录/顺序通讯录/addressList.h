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

//��ʼ��ͨѶ¼
void adListInit(addList L);


//����
void checkcapacity(addList L);


//�����ϵ��
void adListadd(addList L);


//������ϵ��
int adListFind(addList L);

//ɾ����ϵ��

void adListDelete(addList L);

//�޸���ϵ��

void adListchange(addList L);


//��ӡ��ϵ��
void adListshow(addList L);