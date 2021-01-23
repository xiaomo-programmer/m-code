struct ListNode* FindKthToTail(struct ListNode* pListHead, int k) {
	// write code here
	if (pListHead == NULL)
	{
		return NULL;
	}
	int count = 0;
	struct ListNode* cur = pListHead;
	while (cur)
	{
		cur = cur->next;
		count++;
	}
	if (count<k)
	{
		return NULL;
	}
	struct ListNode* slow = pListHead;
	struct ListNode* fast = pListHead;
	while (k--)
	{
		fast = fast->next;
	}
	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	return slow;

}