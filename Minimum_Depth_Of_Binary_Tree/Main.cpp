// Problem: Minimum Depth of Binary Tree

// «ä¸ô:

#include <iostream>
#include <string>


// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	void dfs_traversal(TreeNode *node, int curr_depth)
	{
		if (node->left)
		{
			dfs_traversal(node->left, curr_depth + 1);
		}

		if (node->right)
		{
			dfs_traversal(node->right, curr_depth + 1);
		}

		// do the following only if we're at a leaf node, 
		// otherwise we cannot tell if we are at a leaf node 
		// or if we are returning to a root node after traversing its children
		if (!node->left && !node->right)
		{
			if (curr_depth < min_depth)
				this->min_depth = curr_depth;
		}
	}

	int minDepth(TreeNode* root) {
		if (!root)
		{
			return 0;
		}
		else
		{
			dfs_traversal(root, 1);
		}
		
		return this->min_depth;
	}

private:
	int min_depth = INT_MAX;
};

int main(int argc, char *argv[])
{
	Solution *soln = new Solution();

	TreeNode *root = new TreeNode(1);
	TreeNode *node_l = new TreeNode(2);
	TreeNode *node_r = new TreeNode(3);

	root->left = node_l;
	root->right = node_r;

	std::cout << soln->minDepth(root) << std::endl;

	return 0;
}