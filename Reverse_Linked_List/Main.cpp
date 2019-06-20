// Problem: Reverse Linked List

// Thought Process:
// Method 1: Iterative solution:
// Iterate through the list, pushing each element into the stack as we go. When we reach the end of the list,
// start popping nodes off from the stack. As we pop each node off, we set its 'next' to refer to the node that's sitting on the top of the stack.
// Do so until we popped everything off the stack.

// Method 2: Recursive solution:
// Use recursion to reach the end of the list, set the new list head, then modify the link for each node as we unwind the recursion call stack.
// Note that this process is done "in-place" (without using additional memory space or data structure)

#include <iostream>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode* reverseList(ListNode* head) {
		// iterative solution
		//return reverseListIterative(head);

		// recursive solution
		ListNode* tmp = nullptr;
		return reverseListRecurisve(head, true, &tmp);
	}

	// Recursive solution
	ListNode* reverseListRecurisve(ListNode* head, bool is_original_head, ListNode** reversed_head) {
		// empty list
		if (!head) {
			return nullptr;
		}

		// when we reach the last node, this is base case
		if (head && !head->next) {
			*reversed_head = head;
			return head;
		}
		else {
			ListNode* prev = reverseListRecurisve(head->next, false, reversed_head);	// this represents the previous node in the "reversed list"
			prev->next = head;	// make the previous node (prev) connected to current node (head)
			head->next = nullptr;	// break the link of the original list
			if (is_original_head) {
				// we've reached the original list's head, that means the  list had been reversed, return the new 'reversed head'
				return *reversed_head;
			}
			else {
				// return current node to be used as 'previous node' in the recursive call stack immediately before current call stack
				return head;
			}
		}

		// this should never occur, but is needed for LeetCode OJ, otherwise may encounter "control reach non-void function" error
		return nullptr;
	}

	// Iterative solution
	ListNode* reverseListIterative(ListNode* head) {
		if (!head)
			return nullptr;

		stack<ListNode*> nodes;

		// push nodes into stack
		while (head) {
			nodes.push(head);
			head = head->next;
		}

		// make head points to the last node in the list, which is now sitting on the top of the stack
		head = nodes.top();
		ListNode* tmp = head;

		// start to build the list in reverse order
		while (!nodes.empty()) {
			nodes.pop();
			if (!nodes.empty()) {
				tmp->next = nodes.top();
				tmp = tmp->next;
			}
			else {
				// reaching the last element in the stack, make sure it's next pointer is set to null
				tmp->next = nullptr;
			}
		}

		return head;
	}
};

int main() {
	ListNode *n1 = new ListNode(1);
	ListNode *n2 = new ListNode(2);
	ListNode *n3 = new ListNode(3);
	ListNode *n4 = new ListNode(4);
	ListNode *n5 = new ListNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	Solution* soln = new Solution();
	ListNode* head = soln->reverseList(n1);

	return 0;
}