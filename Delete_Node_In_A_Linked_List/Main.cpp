// Problem: Delete Node In A Linked List

// Algorithm (Ref: Cracking the coding interview 6e)
// We only have access to the node to be deleted. We need to copy next node's value to this node, and make this node's next pointer
// point to the next next node, and break the next node from the linked-list structure.

#include <cstdlib>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	void deleteNode(ListNode* node) {
		// preserve next node's val
		int next_val = node->next->val;
		// preserve next next node's address
		ListNode* tmp = node->next->next;

		// break the next node from the list structure
		node->next->next = nullptr;

		// make current node to be the same as the original next node
		node->val = next_val;
		node->next = tmp;
	}
};