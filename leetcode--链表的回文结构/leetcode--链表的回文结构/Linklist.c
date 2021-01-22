struct ListNode* reverseList(struct ListNode* head){
	struct ListNode* newnode = NULL;
	struct ListNode* cur = head;
	while (cur)
	{
		struct ListNode* next = cur->next;
		cur->next = newnode;
		newnode = cur;
		cur = next;
	}
	return newnode;
}
class PalindromeList {
public:
	bool chkPalindrome(ListNode* A) {
		// write code here
		ListNode* fast = A;
		ListNode* slow = A;
		ListNode* prev = NULL;

		while (fast && fast->next)
		{
			prev = slow;
			slow = slow->next;
			fast = fast->next->next;
		}
		prev->next = NULL;


		slow = reverseList(slow);
		while (A)
		{
			if (A->val != slow->val)
			{
				return false;
			}
			else
			{
				A = A->next;
				slow = slow->next;
			}
		}
		return true;

	}
};