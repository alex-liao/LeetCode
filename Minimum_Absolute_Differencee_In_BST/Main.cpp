// Problem: Minimum Absolute Difference in BST
// Algorithm:
// Method 1 (My own solution):
// 1. Using in-order traversal, we get to visit the nodes in increasing order.
// 2. Add the nodes' values into a vector/array
// 3. Iterate through the vector and compare elements pair by pair to find the minimum absolute difference

// Method 2 (Ref: Grandyang):
// Similar logic to my solution, but does not use a vector.
// Simply use pointers to keep track of previous and current nodes and compare diffs as we traverse.

#include <algorithm>
#include "BinaryTreeHelper.h"

using namespace std;

class Solution {
public:
	int getMinimumDifference(TreeNode* root) {
		vector<int> nodes;

		// in-order traverse the tree
		getMinimumDifferenceRecursive(root, nodes);

		// iterate through the vector, finding the diffs between pairs of elements
		int min_diff = INT_MAX;
		for (int i = 1; i < nodes.size(); i++) {
			int diff = abs(nodes[i] - nodes[i - 1]);
			if (diff < min_diff) {
				min_diff = diff;
			}
		}

		return min_diff;
	}

private:
	void getMinimumDifferenceRecursive(TreeNode* root, vector<int>& nodes) {
		if (!root) {
			return;
		}

		getMinimumDifferenceRecursive(root->left, nodes);

		nodes.push_back(root->val);

		getMinimumDifferenceRecursive(root->right, nodes);
	}
};

// Without using vector
class Solution2 {
public:
	int getMinimumDifference(TreeNode* root) {
		vector<int> nodes;

		TreeNode* prev = nullptr;
		int min_diff = INT_MAX;

		getMinimumDifferenceRecursive(root, prev, min_diff);

		return min_diff;
	}

private:
	void getMinimumDifferenceRecursive(TreeNode* root, TreeNode*& prev, int& min_diff) {
		if (!root) {
			return;
		}

		getMinimumDifferenceRecursive(root->left, prev, min_diff);
		if (prev) {
			int abs_diff = abs(prev->val - root->val);
			if (abs_diff < min_diff) {
				min_diff = abs_diff;
			}
		}
		prev = root;
		getMinimumDifferenceRecursive(root->right, prev, min_diff);
	}
};