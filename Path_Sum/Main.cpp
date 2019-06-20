#include <string>
#include <iostream>

using namespace std;

// Problem: Path Sum

// «ä¸ô:

/**
* Definition for a binary tree node.
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum) {
		int current_sum = 0;
		return dfs_recursion(root, sum, current_sum);
	}

	bool dfs_recursion(TreeNode *root, int target_sum, int current_sum)
	{
		if (!root)
			return false;

		if (!root->left && !root->right)
		{
			if (target_sum == (current_sum + root->val))
				return true;
			else
				return false;
		}
		else
		{
			return (dfs_recursion(root->left, target_sum, (current_sum + root->val)) || dfs_recursion(root->right, target_sum, (current_sum + root->val)));
		}
	}
};