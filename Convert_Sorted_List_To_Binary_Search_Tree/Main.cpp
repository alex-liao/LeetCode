// Problem: Convert Sorted List to Binary Search Tree

// Thought Process:
// Solution 1 (My own solution):
// 1. Using fast/slow pointers to find the mid and end of the linked list, then use the mid as the root
// 2. Use 1..(mid - 1) segment of the list to build the left sub-tree, also use fast/slow pointer to find the mid/end of the sublist
// 3. Use (mid + 1)..end segment of the list to build the right sub-tree, also use fast/slow pointer to find the mid/end of the sublist
// 4. Repeat the process until we have no more sublists

// Solution 2 (My own solution):
// 1. Traverse the linked list and shove the nodes into a vecotr
// 2. Build the tree as if we're building from an array, not linked list

#include <cstdlib>

#include <stdint.h>
#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

// Definition for a binary tree node.
struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	TreeNode* sortedListToBST(ListNode* head) {
		return sortedListToBSTRecursive(head, nullptr);
	}

	// The 'list_end' parameter is one node after the last node in the linked list. It should be considered as not part of the list.
	TreeNode* sortedListToBSTRecursive(ListNode* head, ListNode* list_end) {
		// head == list_end should also be considered as having reached the absolute end of the list
		if (!head || (head == list_end)) {
			return nullptr;
		}

		ListNode* slow = head, *fast = head;
		
		// use slow/fast pointer to find the middle/end of list
		while (fast && fast->next && (fast != list_end) && (fast->next != list_end)) {
			slow = slow->next;
			fast = fast->next->next;
		}

		TreeNode* root = new TreeNode(slow->val);

		// if we have more than 1 node left in our list, continue with building the sub-tree
		if (fast != slow) {
			root->left = sortedListToBSTRecursive(head, slow);
			
			if (!fast || (fast == list_end)) {
				// list length is even, fast pointer points to null, just pass 'fast' as end of list
				root->right = sortedListToBSTRecursive(slow->next, fast);
			}
			else {
				// list length is odd, fast pointer points to last node, need to pass 'fast->next' as end of list
				root->right = sortedListToBSTRecursive(slow->next, fast->next);
			}
		}

		return root;
	}
};

int main(void) {
	uint32_t n = 1011;

	cout << n << endl;

	return 0;
}