typedef struct ListNode Node;
struct ListNode* reverseList(struct ListNode* head){
	Node* newnode = NULL;
	Node* cur = head;
	while (cur)
	{
		Node* next = cur->next;
		cur->next = newnode;
		newnode = cur;
		cur = next;
	}
	return newnode;
}