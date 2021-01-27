typedef struct ListNode Node;
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	Node* cur1 = headA;
	Node* cur2 = headB;
	int a = 0; int b = 0;

	//��������������ĳ���
	while (cur1)
	{
		cur1 = cur1->next;
		a++;
	}

	while (cur2)
	{
		cur2 = cur2->next;
		b++;

	}
	Node* longList = headA;
	Node* shortList = headB;
	if (a<b)
	{
		longList = headB;
		shortList = headA;
	}

	int c = abs(a - b);
	while (c--)
	{
		longList = longList->next;
	}
	//���ཻ��λ��
	while (longList)
	{
		if (longList == shortList)
		{
			return longList;
		}

		longList = longList->next;
		shortList = shortList->next;
	}
	return NULL;
}