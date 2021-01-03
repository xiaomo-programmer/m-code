
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define false 0
//动态顺序表
typedef char ElementData;
typedef struct SeqList
{
	ElementData* a;
	int size;
	int capacity;//容量

}SeqList;

//初始化
void SeqListInit(SeqList* L);
void SeqListPrintf(SeqList* L);
void SeqListCheckCapacity(SeqList* L);
//尾插尾删
void SeqListPushBack(SeqList* L, ElementData x);
void SeqListPopBack(SeqList* L);
//头插头删
void SeqListPushFront(SeqList* L, ElementData x);
void SeqListPopFront(SeqList* L);
//中间插入
void SeqListInsert(SeqList* L, int pos, ElementData x);
//中间删除
void SeqListErase(SeqList* L, int pos);
//查找
int SeqListsearch(SeqList*L, ElementData x);
//删除
int SeqListDestory(SeqList*L, ElementData x);
