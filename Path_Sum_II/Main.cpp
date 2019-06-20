// Problem: Path Sum II

// Thought Process:
// Method 1 (My solution):
// Use DFS to traverse each path, passing a ref to a vector to represent the path we've travelled so far, and a ref to the output vector
// When reaching a leaf node, perform the sum and check if it is the sum we're looking for. If yes, add the path vector to output vector
// Otherwise, go up a level and continue with traversal.
// Remember to remove the current node from the path vector before we return from a recursive call.

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
	vector<vector<int>> pathSum(TreeNode* root, int sum) {
		vector<vector<int>> output;
		if (root) {
			vector<int> path;
			pathSumRecursive(root, sum, path, output);
		}
		return output;
	}

private:
	void pathSumRecursive(TreeNode* root, int target_sum, vector<int>& path, vector<vector<int>>& output) {
		path.push_back(root->val);
		
		if (root->left) {
			pathSumRecursive(root->left, target_sum, path, output);
		}

		if (root->right) {
			pathSumRecursive(root->right, target_sum, path, output);
		}

		// reached a leaf node, path is complete, now calculate the sum
		if (!(root->left) && !(root->right)) {
			int sum = 0;
			for (int i = 0; i < path.size(); i++) {
				sum += path[i];
			}
			// if the path has the sum that we are looking for, add the path we found to output
			if (sum == target_sum) {
				output.push_back(path);
			}
		}

		// remember to remove current node from the path vector when we return (because we are using a reference)
		path.pop_back();
	}
};