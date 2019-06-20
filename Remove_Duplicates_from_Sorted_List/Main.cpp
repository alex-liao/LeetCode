#include <string>
#include <iostream>

// Problem: Remove Duplicates from Sorted List

// «ä¸ô:

using namespace std;

/**
* Definition for singly-linked list.
*/
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// solving the problem in-place
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {
		ListNode *curr = head, *tmp = curr ? curr->next : NULL;

		while (curr)
		{
			while (tmp)
			{
				if (tmp->val != curr->val)
					break;
				tmp = tmp->next;
			}

			curr->next = tmp;
			curr = tmp;
			tmp = curr ? curr->next : NULL;
		}

		return head;
	}
};