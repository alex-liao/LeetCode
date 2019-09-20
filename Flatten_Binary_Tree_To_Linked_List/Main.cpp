// Problem: Flatten Binary Tree To Linked List

// Algorithm 1 (my own solution):
// The linked list nodes are from pre-order traversal of the tree's nodes,
// so we can use pre-order traversal to push the tree nodes into a vector first.
// When we have all nodes in the vector, we can traverse the vector and for each
// node (except for the last node), set its right child as the next node in the
// vector. When we get to the last node, simply set both of its children as null.

#include <vector>
#include "BinaryTreeHelper.h"

using namespace std;

class Solution {
public:
	void flatten(TreeNode* root) {
		vector<TreeNode*> nodes;
		// pre-order traverse the tree and push each node into a linear vector
		flatten_recursive(nodes, root);

		size_t len = nodes.size();

		// rebuild the tree using the nodes in the linear list
		for (int i = 0; i<len; i++) {
			nodes[i]->left = nullptr;
			// not the final node, set the right child as the next node in the list
			if (i != len - 1) {
				nodes[i]->right = nodes[i + 1];
			}
			// the last node, set the right child as null
			else {
				nodes[i]->right = nullptr;
			}
		}
	}

	// pre-order traversal the tree, storing pointers to nodes in linear list
	void flatten_recursive(vector<TreeNode*>& nodes, TreeNode* root) {
		if (root) {
			nodes.push_back(root);
			flatten_recursive(nodes, root->left);
			flatten_recursive(nodes, root->right);
		}
	}
};