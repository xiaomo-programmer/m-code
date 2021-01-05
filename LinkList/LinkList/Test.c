#include"LinkList.h"



void test2()
{
	Node* PList = NULL;
	LinkListPushBack(&PList, 1);
	LinkListPushBack(&PList, 2);
	LinkListPushBack(&PList, 3);
	LinkListPushBack(&PList, 4);
	LinkListPushBack(&PList, 5);
	LinkListPrint(&PList);
	Node* pos = LinkListFind(PList, 4);
	if (pos)
	{
		LinkListInsert(pos, 6);

	}
	LinkListPrint(&PList);
	Node* pos1 = LinkListFind(PList, 2);
	LinkListDelete(pos1);
	LinkListPrint(&PList);
}








int main()
{
	//Node* PList = NULL;

	////Î²²åÎ²É¾
	//LinkListPushBack(&PList, 1);
	//LinkListPushBack(&PList, 2);
	//LinkListPushBack(&PList, 3);
	//LinkListPrint(&PList);
	//LinkListPopBack(&PList);
	//LinkListPopBack(&PList);
	//LinkListPrint(&PList);
	////Í·²åÍ·É¾
	//LinkListPushFront(&PList,4);
	//LinkListPushFront(&PList,5);
	//LinkListPrint(&PList);
	//LinkListPopFront(&PList);
	//LinkListPopFront(&PList);
	//LinkListPrint(&PList);
	//LinkListPopFront(&PList);
	//LinkListPrint(&PList);
	//
	test2();
	return 0;
}