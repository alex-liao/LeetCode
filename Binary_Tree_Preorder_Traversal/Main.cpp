// Problem: Binary Tree Preorder Traversal

// «ä¸ô:
// Algorithm 1 (Recurisve solution):
// If root exists, add root node's value into output vector, then call the function recurisvely onl the 
// root's left and right children nodes

// Algorithm 2 (Recurisve solution):
// TBD

#include <vector>

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

// Algorithm 2: (Recursive solution)
class Solution2 {
public:
	vector<int> preorderTraversal(TreeNode* root) {
	}
};