#include"List.h"

//�����ڵ�
Node* BuyListNode(ElementTypeData x)
{
	Node* Newnode = (Node*)malloc(sizeof(Node));
	Newnode->next = NULL;
	Newnode->prev = NULL;
	Newnode->data = x;

	return Newnode;
}
//��ӡ����
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


//β��
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


//βɾ
void ListPopBack(Node* pHead)
{
	assert(pHead);
	Node* tail = pHead->prev;
	Node* tailprev = tail->prev;
	pHead->prev = tailprev;
	tailprev->next = pHead;
	free(tail);
	
}



//ͷ��
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
//ͷɾ
void ListPopFront(Node* pHead)
{
	assert(pHead);
	Node* cur = pHead->next;
	Node* curnext = cur->next;

	pHead->next = curnext;
	curnext->prev = pHead;
	free(cur);
}


// ˫���������
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

// ˫��������pos��ǰ����в���
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


// ˫������ɾ��posλ�õĽڵ�
void ListErase(Node* pos)
{
	assert(pos);
	Node* posprev = pos->prev;
	Node* posnext = pos->next;

	posprev->next = posnext;
	posnext->prev = posprev;
}
