#include"LinkList.h"


//给新节点申请空间
Node* BuyListNode(Elementdatatype x)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode == NULL)
	{
		printf("申请空间失败");
		exit(-1);
	}
	NewNode->data = x;
	NewNode->next = NULL;

	return NewNode;
}


//打印链表
void LinkListPrint(Node** PPhead)
{
	Node* cur = *PPhead;
	while (cur != NULL)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}


//尾插
void LinkListPushBack(Node** PPhead, Elementdatatype x)
{
	Node* NewNode = BuyListNode(x);
	if (*PPhead==NULL)
	{
		*PPhead = NewNode;
	}
	else
	{
		Node* cur = *PPhead;
		while (cur->next != NULL)
		{
			cur = cur->next;

		}

		
	

		cur->next = NewNode;
	}
}

//尾删
void LinkListPopBack(Node** PPhead)
{
	if (*PPhead == NULL)              //情况一无节点
	{
		return;
	}
	else if ((*PPhead)->next == NULL) //二有一个节点
	{
		free(*PPhead);
		return NULL;
	}
	else                              //两个或两个以上个节点
	{
		Node* prev = NULL;
		Node* Tail = *PPhead;
		while (Tail->next != NULL)
		{
			prev = Tail;
			Tail = Tail->next;
		}
		free(Tail);
		prev->next = NULL;
	}
}



//头插
void LinkListPushFront(Node** PPhead, Elementdatatype x)
{
	Node* NewNode = BuyListNode(x);
	NewNode->next = *PPhead;
	*PPhead = NewNode;
}



//头删
void LinkListPopFront(Node** PPhead)
{
	if (*PPhead == NULL)
	{
		return;
	}
	else
	{
		Node* cur = (*PPhead)->next;
		free(*PPhead);
		*PPhead = cur;
	}
}

//查找
Node* LinkListFind(Node* Phead, Elementdatatype x)
{
	Node* cur = Phead;
	while (cur)
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




//插入
void LinkListInsert(Node* pos, Elementdatatype x)
{
	
	Node* NewNode = BuyListNode(x);
	NewNode->next = pos->next;
	pos->next = NewNode;
}


//删除
void LinkListDelete(Node* pos)
{
	if (pos->next != NULL)
	{
		Node* next = pos->next;
		Node* cur = next->next;
		pos->next = cur;
		free(next);
	}
}