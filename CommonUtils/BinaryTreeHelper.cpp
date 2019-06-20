#include <string>
#include <queue>

#include "BinaryTreeHelper.h"

using namespace std;

TreeNode* BinaryTreeHelper::buildTree(vector<long> input) {
	TreeNode* root = nullptr;

	if (!input.empty() && input[0] != LONG_MIN) {
		queue<TreeNode*> q;
		root = new TreeNode(input[0]);

		q.push(root);
		q.push(nullptr);	// nullptr represents the end of a layer

		int i = 1;	// index for accessing input vector

		// which side are we currently processing?
		// 0 means left child, while 1 means right child
		int child = 0;
		int input_len = input.size();

		while (i < input_len) {
			TreeNode* front = q.front();
			
			// reached the end of a level
			if (!front) {
				q.pop();
				q.push(nullptr);
				child = 0;
				continue;
			}
			else {
				// left node
				if (child == 0) {
					child = 1;
					// the null in input vector should be converted (manually?) to LONG_MIN before passing into this function
					// not using INT_MIN because it may be a valid input value
					if (input[i] != LONG_MIN) {
						front->left = new TreeNode(input[i]);
						q.push(front->left);
					}
				}
				// right node
				else {
					q.pop();
					// the null in input vector should be converted (manually?) to LONG_MIN before passing into this function
					// not using INT_MIN because it may be a valid input value
					if (input[i] != LONG_MIN) {
						front->right = new TreeNode(input[i]);
						q.push(front->right);
					}
					child = 0;
				}
				i++;
			}
		}
	}

	return root;
}