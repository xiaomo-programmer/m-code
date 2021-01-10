#include"List.h"


void test1()
{
	Node* L = NULL;
	ListInit(&L);
	ListPushBack(L, 1);
	ListPushBack(L, 2);
	ListPushBack(L, 3);
	ListPushBack(L, 4);
	ListPushBack(L, 5);
	ListNodePrint(L);
	ListPopBack(L);
	ListPopBack(L);
	ListPopBack(L);
	ListNodePrint(L);
	ListPushFront(L, 6);
	ListPushFront(L, 7);
	ListNodePrint(L);
	ListPopFront(L);
	ListPopFront(L);
	ListNodePrint(L);
	ListFind(L, 3);
}


void test2()
{
	Node* head = NULL;
	ListInit(&head);
	ListPushBack(head, 1);
	ListPushBack(head, 2);
	ListPushBack(head, 3);
	ListPushBack(head, 4);
	ListPushBack(head, 5);
	ListNodePrint(head);

	Node* pos = ListFind(head, 3);
	ListInsert(pos, 9);
	ListNodePrint(head);
	Node* pos1 = ListFind(head, 1);
	ListErase(pos1);
	ListNodePrint(head);
}

int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}