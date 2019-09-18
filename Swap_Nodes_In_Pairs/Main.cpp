// Problem: Swap Nodes in Pairs

// Algorithm 1 (my own solution):
// We can divide the input list into two parts: the "already reversed" part and the "remainder part"
// We set a pointer 'remainder_head' to point to the head of the remainder list, and set a pointer
// 'reversed_list_tail' to point to the tail of the already reversed list.
// We then look at the problem as "processing through the remainder list by 2 nodes at a time".
// During each iteration, we do the following:
// 1. Reverse the node pairs
// 2. Update 'reversed_list_tail' so that it points to the current pair of the reversed nodes
// 3. Update 'remainder_head' so that it moves to the head of the list that is not yet reversed
// We continue doing this when we either have no nodes or only 1 node left, since there's nothing left
// to reverse.

#include "ListNode.h"

class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		if (!head || !head->next) {
			// if list is null or has only 1 node, return the head
			return head;
		}

		bool first_pair = true;
		ListNode* first = nullptr, *second = nullptr, *third = nullptr, *tmp = nullptr, *remainder_head = head, *reversed_list_tail = nullptr;

		do {
			// swap the first and second nodes here
			first = remainder_head;
			second = remainder_head->next;
			third = second->next;
			// reverse the links for the pair of nodes
			second->next = first;
			first->next = third;
			if (first_pair) {
				head = second;	// set the true head
				first_pair = false;
			}
			if (reversed_list_tail) {
				// if there were previous node pairs, need to make the previous 
				// tail node point to current pair of reversed nodes
				reversed_list_tail->next = second;
			}
			reversed_list_tail = first;
			remainder_head = third;
		} while (remainder_head && remainder_head->next);

		return head;
	}
};
