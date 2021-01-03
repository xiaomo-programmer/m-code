

#include"SeqList.h"



void TestSeqListPushBack()
{
	SeqList S;
	SeqListInit(&S);
	//尾插
	SeqListPushBack(&S, 1);
	SeqListPushBack(&S, 2);
	SeqListPushBack(&S, 3);
	SeqListPushBack(&S, 6);
	SeqListPushBack(&S, 7);
	SeqListPushBack(&S, 8);
	SeqListPrint(&S);
	//尾删
	SeqListPopBack(&S);
	SeqListPopBack(&S);
	SeqListPrint(&S);
	//头插
	SeqListPushFront(&S, 10);
	SeqListPushFront(&S, 9);
	SeqListPrint(&S);
	//头删
	SeqListPopFront(&S);
	SeqListPopFront(&S);
	SeqListPrint(&S);
	//中间插
	SeqListInsert(&S, 2, -1);
	SeqListPrint(&S);
	//中间删
	SeqListErase(&S, 3);
	SeqListPrint(&S);
	//查找
	SeqListsearch(&S, -1);
	SeqListPrint(&S);
	//删除
	SeqListDestory(&S,-1);
	SeqListDestory(&S, 6);
	
	
}

int main()
{
	TestSeqListPushBack();
	return 0;
}