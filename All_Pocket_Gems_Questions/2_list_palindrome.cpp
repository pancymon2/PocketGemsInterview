class ListNode
{
public:
	ListNode(int v) :val(v) {}
	int val;
	ListNode* next;
};

class SolutionNew {
public:
	bool isPalindrome(ListNode* head) {
		if (!head)
			return true;
		return helper(&head, head);
	}

	bool helper(ListNode** left, ListNode* right)
	{
		if (!right)
			return true;

		bool is_p = helper(left, right->next);
		if (!is_p)
			return false;

		if ((*left)->val != right->val)
			return false;

		*left = (*left)->next;

		return true;
	}
};

class Solution {
public:
	bool isPalindrome(ListNode* head) {
		if (!head || !head->next)
			return true;
		ListNode* fast = head;
		ListNode* slow = head;
		while (fast&&fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		if (!fast)
		{
			slow = Reverse(slow);
			return IsPrefix(head, slow);
		}
		else
		{
			slow->next = Reverse(slow->next);
			return IsPrefix(head, slow->next);
		}
		return false;
	}



private:
	bool IsPrefix(ListNode* longger, ListNode* shorter)
	{
		while (shorter)
		{
			if (longger->val != shorter->val)
				return false;
			longger = longger->next;
			shorter = shorter->next;
		}
		return true;
	}

	ListNode* Reverse(ListNode* head)
	{
		if (!head || !head->next)
			return head;
		ListNode* first = nullptr;
		ListNode* second = head;
		ListNode* third = head->next;
		while (third)
		{
			second->next = first;
			first = second;
			second = third;
			third = third->next;
		}
		second->next = first;
		return second;
	}

};