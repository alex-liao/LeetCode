// Problem: Sum of Left Leaves

// Algorithm:
// Method 1 (My own solution):
// Use recursion to traverse the tree. When reaching a leaf node, check if it is a left leaf.
// If so, add its node value to a running sum (passed by reference)

#include "TreeNode.h"

class Solution {
public:
	int sumOfLeftLeaves(TreeNode* root) {
		int sum = 0;
		sumOfLeftLeavesRecursive(root, sum, false);

		return sum;
	}

private:
	void sumOfLeftLeavesRecursive(TreeNode* root, int& sum, bool is_left_child) {
		if (!root) {
			return;
		}

		// we arrived at a left leaf
		if ((!root->left && !root->right) && is_left_child) {
			sum += root->val;
			return;
		}

		if (root->left) {
			sumOfLeftLeavesRecursive(root->left, sum, true);
		}

		if (root->right) {
			sumOfLeftLeavesRecursive(root->right, sum, false);
		}
	}
};

int main(int argc, char* argv[]) {
	return 0;
}