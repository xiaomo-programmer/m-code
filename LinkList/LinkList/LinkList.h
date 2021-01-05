#include<stdio.h>
#include<stdlib.h>


typedef int Elementdatatype;

//链表结构体
typedef struct Node
{
	Elementdatatype data;
	struct Node* next;
}Node;

//头节点 尾节点
//struct SList
//{
//	Node* head;
//	Node* tail;
//};

//打印链表
void LinkListPrint(Node** PPHead);






//尾删尾插
void LinkListPushBack(Node** PPhead, Elementdatatype x);
void LinkListPopBack(Node* Phead);

//头删头插
void LinkListPushFront(Node** PPhead, Elementdatatype x);
void LinkListPopFront(Node** PPhead);

//查找
Node* LinkListFind(Node* Phead, Elementdatatype x);

//插入
void LinkListInsert(Node* pos, Elementdatatype x);


//删除
void LinkListDelete(Node* pos);