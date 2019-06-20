#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct node {
	int value;
	struct node *next;
} NODE;

typedef NODE *NodePtr;

class MedianFinder {
public:
	/** initialize your data structure here. */
	MedianFinder() {

	}

	void addNum(int num) {
		// create the new node
		NodePtr new_node = (NodePtr)malloc(sizeof(NODE));
		new_node->value = num;
		new_node->next = nullptr;

		// find the correct place to insert the new node in the list, using insertion sort
		if (head == nullptr)
		{
			head = new_node;
		}
		else
		{
			NodePtr ptr = head;
			while (ptr->value <= new_node->value)
			{
				if (!ptr->next)
					break;
				else
				{
					// peek at next node
					if (ptr->next->value >= new_node->value)
						break;
					else
						ptr = ptr->next;
				}
			}
			// found the location to insert, do insert here
			// current node value is greater than new node, new node becomes the new head
			if (ptr->value > new_node->value)
			{
				head = new_node;
				head->next = ptr;
			}
			else
			{
				// insert after the current node
				NodePtr tmp = ptr->next;
				ptr->next = new_node;
				new_node->next = tmp;
			}
		}

		// keep a count of the number of elements in this linked list
		count++;
	}

	double findMedian() {
		if (count == 1)
		{
			return head->value;
		}

		int index = count / 2;
		NodePtr tmp = head;
		if (count % 2 == 0)
		{
			// even number of items
			for (int i = 1; i < index; i++)
			{
				tmp = tmp->next;
			}
			double val1 = tmp->value;
			tmp = tmp->next;
			double val2 = tmp->value;
			return (val1 + val2) / 2;
		}
		else
		{
			// odd number of items
			for (int i = 1; i < index; i++)
			{
				tmp = tmp->next;
			}
			tmp = tmp->next;
			return tmp->value;
		}
	}

	void printData()
	{
		NodePtr ptr = head;
		while (ptr)
		{
			std::cout << ptr->value << std::endl;
			ptr = ptr->next;
		}
	}
private:
	NODE *head = nullptr;
	int count = 0;
};

/**
* Your MedianFinder object will be instantiated and called as such:
* MedianFinder obj = new MedianFinder();
* obj.addNum(num);
* double param_2 = obj.findMedian();
*/
 
int main() {
	MedianFinder *obj = new MedianFinder();
	obj->addNum(3);
	obj->addNum(1);
	obj->addNum(2);
	obj->addNum(4);
	cout << obj->findMedian() << endl;

	return 0;
}