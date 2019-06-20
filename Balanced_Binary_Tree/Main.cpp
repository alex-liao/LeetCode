// Problem: Balanced Binary Tree

// «ä¸ô:
// Method 1 (My own solution):
// When we stand at a particular node, compute the maximum depth of its left and right subtree.
// If the max depth of the subtrees differ by more than 1, return false.
// Otherwise, move on to check the children of the node we just looked at, and repeat this process
// for all the nodes in the tree

// Method 2 (Refer to Cracking the coding interview 6e, q4.4):
// This is an optimization based on Method 1. Make findMaxDepth() check the balanced-ness of the subtrees
// at the same time as it computes the subtrees' heights. If imbalance occurred during the checking, pass
// the error up. Hence we only need to perform isBalanced() at the root node.

#include <iostream>
#include <algorithm>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution1 {
public:
	bool isBalanced(TreeNode* root) {
		if (!root)
			return true;

		int max_depth_left = findMaxDepth(root->left);
		int max_depth_right = findMaxDepth(root->right);

		if (abs(max_depth_left - max_depth_right) > 1)
			return false;
		else
		{
			// need to check all nodes in the tree for their subtree's heights, not just the root

			// This is WRONG!
			// return true;   // test case: [1,2,2,3,null,null,3,4,null,null,4]

			return isBalanced(root->left) && isBalanced(root->right);
		}
	}

	int findMaxDepth(TreeNode *node)
	{
		if (!node)
			return 0;

		return 1 + max(findMaxDepth(node->left), findMaxDepth(node->right));
	}
};

class Solution2 {
public:
	bool isBalanced(TreeNode* root) {
		return findMaxDepth(root) != -1;
	}

private:
	int findMaxDepth(TreeNode *node) {
		if (!node)
			return 0;
		
		int depth_left = findMaxDepth(node->left);
		if (depth_left == -1) {
			return -1;
		}

		int depth_right = findMaxDepth(node->right);
		if (depth_right == -1) {
			return -1;
		}

		int depth_diff = abs(depth_left - depth_right);
		if (depth_diff > 1) {
			// depth difference is greater than 1, this means imbalance occurred, return -1
			return -1;
		}
		else {
			return 1 + max(depth_left, depth_right);
		}
	}
};

int main(int argc, char *argv[])
{
	TreeNode *root = new TreeNode(1);
	TreeNode *n1 = new TreeNode(2);
	TreeNode *n2 = new TreeNode(2);
	TreeNode *n3 = new TreeNode(3);
	TreeNode *n4 = new TreeNode(3);
	TreeNode *n5 = new TreeNode(4);
	TreeNode *n6 = new TreeNode(4);
	
	root->left = n1;
	root->right = n2;

	n1->left = n3;
	n1->right = n4;

	n3->left = n5;
	n3->right = n6;

	Solution1 *soln1 = new Solution1();

	cout << soln1->isBalanced(root) << endl;
	
	return 0;
}