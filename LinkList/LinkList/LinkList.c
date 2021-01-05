#include"LinkList.h"


//���½ڵ�����ռ�
Node* BuyListNode(Elementdatatype x)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	if (NewNode == NULL)
	{
		printf("����ռ�ʧ��");
		exit(-1);
	}
	NewNode->data = x;
	NewNode->next = NULL;

	return NewNode;
}


//��ӡ����
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


//β��
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

//βɾ
void LinkListPopBack(Node** PPhead)
{
	if (*PPhead == NULL)              //���һ�޽ڵ�
	{
		return;
	}
	else if ((*PPhead)->next == NULL) //����һ���ڵ�
	{
		free(*PPhead);
		return NULL;
	}
	else                              //�������������ϸ��ڵ�
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



//ͷ��
void LinkListPushFront(Node** PPhead, Elementdatatype x)
{
	Node* NewNode = BuyListNode(x);
	NewNode->next = *PPhead;
	*PPhead = NewNode;
}



//ͷɾ
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

//����
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




//����
void LinkListInsert(Node* pos, Elementdatatype x)
{
	
	Node* NewNode = BuyListNode(x);
	NewNode->next = pos->next;
	pos->next = NewNode;
}


//ɾ��
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