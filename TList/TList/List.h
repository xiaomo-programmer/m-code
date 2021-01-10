#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
typedef int ElementTypeData;


typedef struct ListNode
{
	struct Node* next;
	struct Node* prev;
	int data;
}Node;


//����ѭ��������ͷ�ڵ�
Node* ListCreate();
// ˫����������
void ListDestory(Node* pHead);

// ˫������β��
void ListPushBack(Node* pHead,ElementTypeData  x);
// ˫������βɾ
void ListPopBack(Node* pHead);
// ˫������ͷ��
void ListPushFront(Node* pHead,ElementTypeData x);
// ˫������ͷɾ
void ListPopFront(Node* pHead);
// ˫���������
Node* ListFind(Node* pHead, ElementTypeData x);
// ˫��������pos��ǰ����в���
void ListInsert(Node* pos,ElementTypeData x);
// ˫������ɾ��posλ�õĽڵ�
void ListErase(Node* pos);


Node* BuyListNode(ElementTypeData x);


//��ӡ����
void ListNodePrint(Node* pHead);

void ListInit(Node** ppHead);