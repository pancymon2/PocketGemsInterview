class ListNode
{
public:
	int val;
	ListNode* next;
};

bool isPalindrome(ListNode* head) {
	if (!head || !head->next)
		return true;
	ListNode* fast = head->next;
	ListNode* slow = head;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	//little tricky here if the size is even, depends on how do you define middle
	return slow;
}