#include <string>
#include <iostream>
#include <algorithm>

// Problem: Maximum Depth of Binary Tree

// «ä¸ô (Alex): ¥Î recursion

using namespace std;

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
	int node_depth(TreeNode *node)
	{
		if (!node)
			return 0;
		else
			return (1 + max(node_depth(node->left), node_depth(node->right)));
	}
	
	int maxDepth(TreeNode* root) {
		return node_depth(root);
	}
};