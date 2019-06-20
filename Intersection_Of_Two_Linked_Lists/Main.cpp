// Problem: Intersection Of Two Linked Lists

// «ä¸ô: (from Grandyang)
// http://www.cnblogs.com/grandyang/p/4128461.html

#include <string>
#include <iostream>

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
	{
		if (!headA || !headB)
			return NULL;

		ListNode *tmp;
		int length_a = 0, length_b = 0;

		// traverse list A to find its length
		for (tmp = headA; tmp != NULL; tmp = tmp->next)
		{
			length_a++;
		}

		// traverse list B to find its length
		for (tmp = headB; tmp != NULL; tmp = tmp->next)
		{
			length_b++;
		}

		// work out the difference in the lists' lengths
		unsigned int leng_diff = abs(length_a - length_b);
		int i = leng_diff;

		// shorten the longer list by moving its pointer forward
		while (i)
		{
			if (length_a > length_b)
			{
				headA = headA->next;
			}
			else
			{
				headB = headB->next;
			}
			i--;
		}

		// now that the lists are of the same lengths, we can start 
		// to find their intersection by moving each of the pointers forward one node at a time
		while (true)
		{
			if (headA == headB)
			{
				return headA;
			}
			else
			{
				headA = headA->next;
				headB = headB->next;
			}
		}
	}

private:
};

int main(int argc, char *argv[])
{
	Solution *soln = new Solution();

	ListNode *a = new ListNode(1);
	ListNode *b = new ListNode(2);

	std::cout << soln->getIntersectionNode(a, b) << std::endl;

	return 0;
}