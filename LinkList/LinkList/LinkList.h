#include<stdio.h>
#include<stdlib.h>


typedef int Elementdatatype;

//����ṹ��
typedef struct Node
{
	Elementdatatype data;
	struct Node* next;
}Node;

//ͷ�ڵ� β�ڵ�
//struct SList
//{
//	Node* head;
//	Node* tail;
//};

//��ӡ����
void LinkListPrint(Node** PPHead);






//βɾβ��
void LinkListPushBack(Node** PPhead, Elementdatatype x);
void LinkListPopBack(Node* Phead);

//ͷɾͷ��
void LinkListPushFront(Node** PPhead, Elementdatatype x);
void LinkListPopFront(Node** PPhead);

//����
Node* LinkListFind(Node* Phead, Elementdatatype x);

//����
void LinkListInsert(Node* pos, Elementdatatype x);


//ɾ��
void LinkListDelete(Node* pos);