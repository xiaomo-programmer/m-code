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


//创建循环链表返回头节点
Node* ListCreate();
// 双向链表销毁
void ListDestory(Node* pHead);

// 双向链表尾插
void ListPushBack(Node* pHead,ElementTypeData  x);
// 双向链表尾删
void ListPopBack(Node* pHead);
// 双向链表头插
void ListPushFront(Node* pHead,ElementTypeData x);
// 双向链表头删
void ListPopFront(Node* pHead);
// 双向链表查找
Node* ListFind(Node* pHead, ElementTypeData x);
// 双向链表在pos的前面进行插入
void ListInsert(Node* pos,ElementTypeData x);
// 双向链表删除pos位置的节点
void ListErase(Node* pos);


Node* BuyListNode(ElementTypeData x);


//打印链表
void ListNodePrint(Node* pHead);

void ListInit(Node** ppHead);