// Problem: Palindrome Linked List

// «ä¸ô: (Refer to "Cracking the Coding Interview 6e" question 2.6 under Chapter 2)
// Method 1 (From book): Use fast/slow pointers
// Method 2 (From book): Use recursion. 
// Method 3 (My own solution): Use recursion + <queue>

#include <stack>
#include <queue>
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	// Using the fast/slow pointer technique (iterative) together with <stack>
	bool isPalindrome1(ListNode* head)
	{
		ListNode* slow = head;
		ListNode* fast = head;
		std::stack<int> vals;

		// iterate the slow/fast pointers until the fast pointer reaches the end of the list
		while (fast && fast->next)
		{
			// push the value of the node pointed by the slow pointer into the stack
			vals.push(slow->val);
			slow = slow->next;
			fast = fast->next->next;
		}

		// when reaching the end of the list, if 'fast' points to null, the length of the list is even, otherwise odd
		// In the case that the list length is odd, the slow pointer will be pointing to the node that is located at the middle of the list and we need to drop that node when performing palindrome comparison
		// In the case that the list length is even, the slow pointer will be pointing to the first node that belongs to the latter part of the list and we can start performing comparision immediately
		if (fast)
			slow = slow->next;

		while (!vals.empty())
		{
			if (vals.top() == slow->val)
			{
				// values equal, pop off the value ont he top of the stack and move on to the next value
				vals.pop();
				slow = slow->next;
			}
			else
				return false;
		}

		return true;
	}

	// the recursive solution, using the double pointer (type **) technique
	bool isPalindrome2(ListNode* head, int length, ListNode** ptr)
	{
		if (length == 0)
		{
			// return true, and make the output parameter point to the current head node
			*ptr = head;
			return true;
		}
		else if (length == 1)
		{
			// return true, and make the output parameter point to head->next node
			*ptr = head->next;
			return true;
		}

		bool is_palindrome = isPalindrome2(head->next, (length - 2), ptr);

		if (!is_palindrome)
		{
			return false;
		}
		else
		{
			if (head->val != (*ptr)->val)
				return false;
			else
			{
				*ptr = ((*ptr)->next);
				return true;
			}
		}
	}

	// Method 3: My own solution. Combine recursion with <queue>
	bool isPalindrome3(ListNode* head)
	{
		if (!head)
			return true;

		std::queue<int> queue;

		// use recursion to add the list nodes from the end of the list to the start into a queue
		isPalindrome3RecursiveCall(head, queue);

		unsigned int queue_len = queue.size();

		ListNode* tmp = head;
		// we only need to examine the first half of the queue
		for (int i = 1; i <= (queue_len / 2); i++)
		{
			if (tmp->val != queue.front())
			{
				return false;
			}
			else
			{
				queue.pop();
				tmp = tmp->next;
			}
		}

		return true;
	}

private:
	void isPalindrome3RecursiveCall(ListNode* head, std::queue<int>& queue)
	{
		// (for base case) for the last node
		if(!(head->next))
		{
			queue.push(head->val);
			return;
		}

		isPalindrome3RecursiveCall(head->next, queue);

		// (for non base case) push current node value into stack
		queue.push(head->val);
		return;
	}
};

int main()
{
	Solution* soln = new Solution();

	// build the nodes
	ListNode* t1 = new ListNode(1);
	ListNode* t2 = new ListNode(2);
	ListNode* t3 = new ListNode(3);
	ListNode* t4 = new ListNode(2);
	ListNode* t5 = new ListNode(1);

	// link the nodes
	t1->next = t2;
	t2->next = t3;
	t3->next = t4;
	t4->next = t5;

	// build the nodes
	ListNode* f1 = new ListNode(1);
	ListNode* f2 = new ListNode(2);
	ListNode* f3 = new ListNode(3);

	// link the nodes
	f1->next = f2;
	f2->next = f3;

	ListNode* list = t1;

	std::cout << "isPalindrome1: " <<  soln->isPalindrome1(list) << std::endl;
	// std::cout << soln->isPalindrome2(n1) << std::endl;
	std::cout << "isPalindrome3: " << soln->isPalindrome3(list) << std::endl;
}