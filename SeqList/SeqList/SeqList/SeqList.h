
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define false 0
//��̬˳���
typedef char ElementData;
typedef struct SeqList
{
	ElementData* a;
	int size;
	int capacity;//����

}SeqList;

//��ʼ��
void SeqListInit(SeqList* L);
void SeqListPrintf(SeqList* L);
void SeqListCheckCapacity(SeqList* L);
//β��βɾ
void SeqListPushBack(SeqList* L, ElementData x);
void SeqListPopBack(SeqList* L);
//ͷ��ͷɾ
void SeqListPushFront(SeqList* L, ElementData x);
void SeqListPopFront(SeqList* L);
//�м����
void SeqListInsert(SeqList* L, int pos, ElementData x);
//�м�ɾ��
void SeqListErase(SeqList* L, int pos);
//����
int SeqListsearch(SeqList*L, ElementData x);
//ɾ��
int SeqListDestory(SeqList*L, ElementData x);
