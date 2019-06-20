// Problem: Binary Tree Paths

// «ä¸ô: 
// Build the path string as we go down each path (using recursion). When we reach a leaf node, we add the completed
// path string to output vector. Repeat the above procedure until we had completely traversed the binary tree.


#include <vector>
#include <string>
#include <iostream>

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
	vector<string> binaryTreePaths(TreeNode* root) {
		vector<string> output;
		string path = "";

		binaryTreePathsRecursiveCall(root, path, output);

		return output;
	}

	void binaryTreePathsRecursiveCall(TreeNode* node, string path, vector<string>& output) {
		if (!node)
			return;
		
		if (!node->left && !node->right) {
			string val_str = to_string(node->val);
			if (path.empty()) {
				path = val_str;
			}
			else {
				path += "->" + val_str;
			}
			// add the path to output vector
			output.push_back(path);
			return;
		}

		// add current node's value to path
		if (path.empty()) {
			path = to_string(node->val);
		}
		else {
			path += "->" + to_string(node->val);
		}

		if (node->left)	{
			binaryTreePathsRecursiveCall(node->left, path, output);
		}
			
		if (node->right) {
			binaryTreePathsRecursiveCall(node->right, path, output);
		}
	}
};