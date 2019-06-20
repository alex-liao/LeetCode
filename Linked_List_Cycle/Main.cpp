// Problem: Linked List Cycle

// «ä¸ô:
// Method 1. use a Set data structure to verify if any pointer points to a memory address we've already seen before
// Method 2. Use fast/slow pointers, if they pointers ever collide, that means there's a cycle within the linked list (refer to the book 'Cracking the coding interview')

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

#include <unordered_set>

using namespace std;

class Solution {
public:
	// Solution using the 'Set' data structure
	bool hasCycle(ListNode *head) {
		ListNode* tmp = head;

		unordered_set<ListNode*> my_set;

		while (tmp)
		{
			if (my_set.find(tmp) == my_set.end())
			{
				my_set.insert(tmp);
				tmp = tmp->next;
			}
			else
			{
				return true;
			}
		}

		return false;
	}

	// fast/slow pointers solution, this uses O(1) space complexity
	bool hasCycle(ListNode* head) {
		ListNode* fast = head;
		ListNode* slow = head;

		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast)
				return true;
		}

		return false;
	}
};