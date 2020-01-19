// Problem: Binary Tree Postorder Traversal

// «ä¸ô:
// Algorithm 1 (Recurisve solution):
// Just the plain old recursive solution. Nothing special here

// Algorithm 2 (Iterative solution, 2 stacks):
// Ref: https://www.geeksforgeeks.org/iterative-postorder-traversal/
// Iterative Postorder Traversal is harder than the other 2 types of traversals done iteratively
// because Postorder Traversal is not tail recursion when it's written in recursive form.
// We first traverse the tree in a "special" pre-order way. Instead of visiting the nodes in the order of
// (root/left/right), we need to do (root/right/left). This gives us the "reversed" post-order traversal.
// If we were to push the values of the nodes that we've visited into a stack, we can then pop them back out
// that gives us "reversed reversed post-order traversal", which would be post-order traversal, which is what
// we want

// Algorithm 3 (Iterative, single stack):
// TBD

#include <vector>
#include <stack>

#include <BinaryTreeHelper.h>

using namespace std;

// Algorithm 1
class Solution1 {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;

		if (!root) {
			return res;
		}

		postorderTraversal(root, res);

		return res;
	}

	void postorderTraversal(TreeNode* root, vector<int>& res) {
		if (root->left) {
			postorderTraversal(root->left, res);
		}
		if (root->right) {
			postorderTraversal(root->right, res);
		}
		res.push_back(root->val);
	}
};

// Algorithm 2
class Solution {
public:
	vector<int> postorderTraversal(TreeNode* root) {
		vector<int> res;
		stack<TreeNode*> nodes;
		stack<int> values;

		if (!root) {
			return res;
		}

		nodes.push(root);

		while (!nodes.empty()) {
			TreeNode* node = nodes.top();
			nodes.pop();
			// push node values into second stack, not the output vector
			values.push(node->val);

			// 'special' pre-order traversal, visit right child first
			// remember, in order to visit right child first, we push the left child into stack first
			if (node->left) {
				nodes.push(node->left);
			}
			// then push right child into stack
			if (node->right) {
				nodes.push(node->right);
			}
		}

		// finally, pop node values out of stack (they are in "reverse postorder traversal" order)
		// and push them into output vector
		while (!values.empty()) {
			int value = values.top();
			values.pop();
			res.push_back(value);
		}

		// finally, return output vector
		return res;
	}
};

// Driver code
int main(int argc, char* argv[]) {
	Solution s;
	
	TreeNode* root = new TreeNode(3);
	root->left = new TreeNode(1);
	root->right = new TreeNode(2);

	s.postorderTraversal(root);
}