// Problem: Binary Tree Inorder Traversal

// Algorithm:

// Method 1:
// Refer to Grandyang

// Method 2:
// Use recursion, nothing special

#include <cstdlib>
#include <vector>
#include <stack>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution 2
// Recursive solution
class Solution2 {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		vector<int> output;
		inorderTraversalRecursive(root, output);

		return output;
	}

	void inorderTraversalRecursive(TreeNode* root, vector<int>& output) {
		if (!root) {
			return;
		}

		inorderTraversalRecursive(root->left, output);
		output.push_back(root->val);
		inorderTraversalRecursive(root->right, output);
	}
};

// Solution 1
// Refer to Grandyang's solution. This converts recursion into iteration by using stacks
class Solution {
public:
	vector<int> inorderTraversal(TreeNode* root) {
		stack<TreeNode*> my_stack;
		vector<int> output;

		TreeNode* node = root;

		while (node || !my_stack.empty()) {
			// adds all nodes along the left path into the stack, 
			while (node) {
				my_stack.push(node);
				node = node->left;
			}

			// when we get to a null along the left path, we get the left most node (for the left subtree) from the top of stack
			// OR
			// when we have a chain of right child nodes only, we get the parent node by popping the stack
			node = my_stack.top();
			my_stack.pop();
			
			// add's the node's value to the output
			output.push_back(node->val);

			// continues the "look along the left path" for the right child node
			node = node->right;
		}

		return output;
	}
};