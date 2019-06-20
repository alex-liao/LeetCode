// Problem: Sum Root To Leaf Numbers

// Thought Process:
// Method 1 (My own solution): Use DFS with queue
// 1. Use a vector to record the individual digits we came across and work out the path's number when we reach a leaf node
// 2. At the leaf node, add the path's number to all path's sum
// 3. Before returning in each recursive call, remove the current node from the path vector
// 4. Continue this process until we've completely traversed the entire tree

// Method 2 (Ref: Grandyang): Use DFS, no other data structure
// https://www.cnblogs.com/grandyang/p/4273700.html

#include <cstdlib>
#include <vector>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
	int sumNumbers(TreeNode* root) {
		vector<TreeNode*> path;
		int paths_sum = 0;
		sumNumbersRecursive(root, path, paths_sum);

		return paths_sum;
	}

private:
	void sumNumbersRecursive(TreeNode* root, vector<TreeNode*>& path, int& paths_sum) {
		if (!root) {
			return;
		}

		// push current node into path vector
		path.push_back(root);

		// if we're at a leaf node, work out the path's number and add it to the paths_sum
		if (!(root->left) && !(root->right)) {
			int multiplier = 1;
			for (int i = (path.size() - 1); i >= 0; i--) {
				paths_sum += multiplier * (path[i]->val);
				
				// ALERT!: perform 10x muliply only if we are n orders of magnitudes less than INT_MAX (2^31-1)
				// otherwise the multiplier overflows
				if ((INT_MAX / multiplier) >= 10) {
					multiplier *= 10;
				}
			}
			
			// remove current node from path vector before we return
			path.pop_back();
			return;
		}

		sumNumbersRecursive(root->left, path, paths_sum);
		sumNumbersRecursive(root->right, path, paths_sum);

		// for non-leaf nodes, remove it from the path vector before return as well
		path.pop_back();
		return;
	}
};