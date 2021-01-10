#include"List.h"

//创建节点
Node* BuyListNode(ElementTypeData x)
{
	Node* Newnode = (Node*)malloc(sizeof(Node));
	Newnode->next = NULL;
	Newnode->prev = NULL;
	Newnode->data = x;

	return Newnode;
}
//打印链表
void ListNodePrint(Node* pHead)
{
	assert(pHead);
	Node* cur = pHead->next;
	while (cur !=pHead)
	{
		printf(" %d ", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void ListInit(Node** ppHead)
{
	*ppHead = BuyListNode(0);
	(*ppHead)->next = *ppHead;
	(*ppHead)->prev = *ppHead;
}


//尾插
void ListPushBack(Node* pHead, ElementTypeData  x)
{
	assert(pHead);
	Node* Tail = pHead->prev;
	Node* NewNode = BuyListNode(x);

	Tail->next = NewNode;
	NewNode->prev = Tail;

	 pHead->prev=NewNode ;
	 NewNode->next = pHead;  
}


//尾删
void ListPopBack(Node* pHead)
{
	assert(pHead);
	Node* tail = pHead->prev;
	Node* tailprev = tail->prev;
	pHead->prev = tailprev;
	tailprev->next = pHead;
	free(tail);
	
}



//头插
void ListPushFront(Node* pHead, ElementTypeData x)
{
	assert(pHead);
	Node* cur = pHead->next;
	Node* newNode = BuyListNode(x);

	newNode->next = pHead->next;
	pHead->next = newNode;
	newNode->prev = cur->prev;
	cur->prev = newNode;

}
//头删
void ListPopFront(Node* pHead)
{
	assert(pHead);
	Node* cur = pHead->next;
	Node* curnext = cur->next;

	pHead->next = curnext;
	curnext->prev = pHead;
	free(cur);
}


// 双向链表查找
Node* ListFind(Node* pHead, ElementTypeData x)
{
	assert(pHead);
	Node* cur = pHead->next;
	while (cur != pHead)
	{
		if (cur->data == x)
		{
			
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
	
}

// 双向链表在pos的前面进行插入
void ListInsert(Node* pos, ElementTypeData x)
{
	assert(pos);
	Node* posprev = pos->prev;
	Node* newNode = BuyListNode(x);

	newNode->next = pos;
	posprev->next = newNode;
	newNode->prev = posprev;
	pos->prev = newNode; 
}


// 双向链表删除pos位置的节点
void ListErase(Node* pos)
{
	assert(pos);
	Node* posprev = pos->prev;
	Node* posnext = pos->next;

	posprev->next = posnext;
	posnext->prev = posprev;
}
