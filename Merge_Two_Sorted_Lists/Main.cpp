#include <iostream>
#include <string>

using namespace std;

// Problem: Merge Two Sorted Lists

// 思路 (有參考 Grandyang & Kamyu):
// 1. Create a new list
// 2. Use l1 & l2 as list1 and list2 iterators
// 3. Pick the smaller element fromt he two lists, insert to the new list that we created
// 4. Repeat the process until one of the list is exhausted
// 5. Append the other unfinished list to the end of the list we are creating

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 實作1 (不創建新的 list，而是用兩個 list 中較小的那個直接當作開始)
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *head = NULL, *curr = NULL;
		
		// one of the given list starts out empty, set head to point to the other non-empty one
		if (!l1 || !l2)
		{
			head = l1 ? l1 : l2;
			if (!head)
			{
				return NULL;
			}

			if (head == l1)
				l1 = l1->next;	// move the head of list to the next element
			else if (head == l2)
				l2 = l2->next;	// move the head of list to the next element
		}
		else
		{
			// figure out which starting element we should set head to point to
			if (l1->val <= l2->val)
			{
				head = l1;
				l1 = l1->next;	// move the head of list to the next element
			}
			else
			{
				head = l2;
				l2 = l2->next;	// move the head of list to the next element
			}
		}

		curr = head;

		while (l1 && l2)
		{
			if (l1->val <= l2->val)
			{
				curr->next = l1;
				l1 = l1->next;
			}
			else
			{
				curr->next = l2;
				l2 = l2->next;
			}
			curr = curr->next;
		}
		
		curr->next = l1 ? l1 : l2;

		return head;
	}
};

int main(int argc, char *argv[])
{
	ListNode *tmp = NULL;
	ListNode *l1 = new ListNode(1);
	tmp = l1;
	tmp->next = new ListNode(2);
	tmp = tmp->next;
	tmp->next = new ListNode(4);
	tmp = tmp->next;

	ListNode *l2 = new ListNode(1);
	tmp = l2;
	tmp->next = new ListNode(3);
	tmp = tmp->next;
	tmp->next = new ListNode(4);
	tmp = tmp->next;

	Solution *soln = new Solution();
	ListNode *res = soln->mergeTwoLists(l1, l2);

	// testing
	while (res)
	{
		cout << res->val;
		if (res->next)
			cout << "->";
		res = res->next;
	}
	cout << endl;

	return 0;
}