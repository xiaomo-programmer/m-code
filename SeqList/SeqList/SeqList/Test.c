

#include"SeqList.h"



void TestSeqListPushBack()
{
	SeqList S;
	SeqListInit(&S);
	//β��
	SeqListPushBack(&S, 1);
	SeqListPushBack(&S, 2);
	SeqListPushBack(&S, 3);
	SeqListPushBack(&S, 6);
	SeqListPushBack(&S, 7);
	SeqListPushBack(&S, 8);
	SeqListPrint(&S);
	//βɾ
	SeqListPopBack(&S);
	SeqListPopBack(&S);
	SeqListPrint(&S);
	//ͷ��
	SeqListPushFront(&S, 10);
	SeqListPushFront(&S, 9);
	SeqListPrint(&S);
	//ͷɾ
	SeqListPopFront(&S);
	SeqListPopFront(&S);
	SeqListPrint(&S);
	//�м��
	SeqListInsert(&S, 2, -1);
	SeqListPrint(&S);
	//�м�ɾ
	SeqListErase(&S, 3);
	SeqListPrint(&S);
	//����
	SeqListsearch(&S, -1);
	SeqListPrint(&S);
	//ɾ��
	SeqListDestory(&S,-1);
	SeqListDestory(&S, 6);
	
	
}

int main()
{
	TestSeqListPushBack();
	return 0;
}