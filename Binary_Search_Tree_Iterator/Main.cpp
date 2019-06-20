// Problem: Binary Search Tree Iterator

// Algorithm:
// Method 1 (My own solution):
// Use the iterative traversal solution with the use of Stack.
// Each time next() gets called:
// 1. We traverse down the left sub-tree path until we find the left-most child, 
//    pushing the left children into the Stack and breaking the link between the
//	  parent and child nodes along the way.
// 2. We get the pointer to the node at the top of the stack
// 3. If the node at the top of the stack has a right child, push the right child
//	  into the stack and break the link between the parent and right-child nodes
// 4. Finally we return the value of the node obtained at step #2

#include <stack>
#include <iostream>

#include "BinaryTreeHelper.h";

using namespace std;

class BSTIterator {
private:
	std::stack<TreeNode*> s;

public:
	BSTIterator(TreeNode* root) {
		if (root) {
			s.push(root);
		}
	}

	/** @return the next smallest number */
	int next() {
		TreeNode* node = s.top();

		// reaching the left most child and push the chain of left children along the path into the stack
		// at each step, also break the link between the parent node and the left child
		while (node->left) {
			TreeNode* left = node->left;
			node->left = nullptr;
			s.push(left);
			node = left;
		}

		// preserve a pointer to the node at the top of the stack, used for returning its value later
		node = s.top();
		s.pop();

		// if the top-of-stack node has a right child, break the link between the node and its right child
		// and push the right child into the stack. This effectively mimics the iterative traversal process
		// for a BST
		if (node->right) {
			TreeNode* right = node->right;
			node->right = nullptr;
			s.push(right);
		}

		// finally, we return the node's value
		return node->val;
	}

	/** @return whether we have a next smallest number */
	bool hasNext() {
		// if the stack is non-empty, then there must be a next smallest number
		if (!s.empty()) {
			return true;
		}
		return false;
	}
};

/**
* Your BSTIterator object will be instantiated and called as such:
* BSTIterator* obj = new BSTIterator(root);
* int param_1 = obj->next();
* bool param_2 = obj->hasNext();
*/

int main(void) {
	BinaryTreeHelper* bst = new BinaryTreeHelper();
	TreeNode* root = bst->buildTree({7, 3, 15, LONG_MIN, LONG_MIN, 9, 20});

	BSTIterator iterator(root);

	cout << iterator.next() << endl;    // return 3
	cout << iterator.next() << endl;    // return 7
	cout << iterator.hasNext() << endl; // return true
	cout << iterator.next() << endl;    // return 9
	cout << iterator.hasNext() << endl; // return true
	cout << iterator.next() << endl;    // return 15
	cout << iterator.hasNext() << endl; // return true
	cout << iterator.next() << endl;    // return 20
	cout << iterator.hasNext() << endl; // return false

	return 0;
}