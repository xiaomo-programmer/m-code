typedef struct ListNode Node;
struct ListNode* insertionSortList(struct ListNode* head){
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	Node* sorthead = head;
	Node* cur = head->next;
	sorthead->next = NULL;
	while (cur)
	{
		Node* next = cur->next;

		if (cur->val<sorthead->val)
		{
			cur->next = sorthead;
			sorthead = cur;
		}
		else
		{
			Node* sortprev = sorthead;
			Node* sortcur = sortprev->next;
			while (sortcur)
			{
				if (cur->val <= sortcur->val)
				{
					sortprev->next = cur;
					cur->next = sortcur;
					break;
				}
				else
				{
					sortprev = sortcur;
					sortcur = sortcur->next;
				}
			}
			if (sortcur == NULL)
			{
				sortprev->next = cur;
				cur->next = NULL;
			}
		}
		cur = next;

	}
	return sorthead;
}