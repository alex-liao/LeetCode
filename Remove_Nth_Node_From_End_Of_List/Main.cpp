// Problem: Remove Nth Node From End of List

// Algorithm:
// Method 1 (My own solution):
// 1. Use recursion to find the nth from end node
// 2. Iterate to one node before the nth from end
// 3. Restructure the list by removing the nth from end

// Method 2 (Ref: Grandyang):
// Using the 'fast/slow' pointer technique (TBD)

using namespace std;

#include "ListNode.h"

class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		if (!head) {
			return nullptr;
		}

		ListNode* tmp = head;
		int i = 0;
		ListNode* nth_from_end = findNthFromEndRecursive(head, n, i);

		// special case handling for if head happens to be the nth from last...
		if (head == nth_from_end) {
			tmp = head->next;
			head->next = nullptr;
			head = tmp;
			return head;
		}

		// find one before nth
		while (tmp->next != nth_from_end) {
			tmp = tmp->next;
		}

		// delete nth from end node
		tmp->next = tmp->next->next;
		nth_from_end->next = nullptr;

		return head;
	}

private:
	ListNode* findNthFromEndRecursive(ListNode* head, int n, int& i) {
		if (!head) {
			return nullptr;
		}

		ListNode* node = findNthFromEndRecursive(head->next, n, i);
		i++;
		if (i == n) {
			return head;
		}

		return node;
	}
};