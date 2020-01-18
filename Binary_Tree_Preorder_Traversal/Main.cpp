// Problem: Binary Tree Preorder Traversal

// «ä¸ô:
// Algorithm 1 (Recurisve solution):
// If root exists, add root node's value into output vector, then call the function recurisvely onl the 
// root's left and right children nodes

// Algorithm 2 (Recurisve solution):
// Ref: https://www.geeksforgeeks.org/iterative-preorder-traversal/
// We need an explicit stack in order to convert the recursive algorithm into iterative process
// The iterative process goes like this:
// 1. While the stack is not empty, we pop the stack and store the popped node's value into the output vector
// 2. In order to visit the left child of a node before the right child node, we need to push the 
//    right child into the stack first (if it exists).
// 3. Then we push the left child node of the popped node into the stack (if it exists).
// 4. Repeat the above steps #1 ~ #3, and we get the pre-order traversal effect.

#include <vector>
#include <stack>

#include "BinaryTreeHelper.h";

using namespace std;

// Algorithm 1: (Recursive solution)
class Solution1 {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		preorderTraversalRecursion(root, res);
		return res;
	}

	void preorderTraversalRecursion(TreeNode* root, vector<int>& res) {
		if (root) {
			res.push_back(root->val);
			preorderTraversalRecursion(root->left, res);
			preorderTraversalRecursion(root->right, res);
		}
	}
};

// Algorithm 2: (Iterative solution)
class Solution {
public:
	vector<int> preorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> s;

		if (!root) {
			return res;
		}

		s.push(root);

		while (!s.empty()) {
			TreeNode* node = s.top();
			s.pop();
			res.push_back(node->val);
			if (node->right) {
				s.push(node->right);
			}
			if (node->left) {
				s.push(node->left);
			}
		}

		return res;
	}
};