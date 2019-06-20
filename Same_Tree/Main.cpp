#include <string>
#include <iostream>
#include <queue>

// Problem: Same Tree

// «ä¸ô:

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
private:
	queue<TreeNode *> t1q;
	queue<TreeNode *> t2q;

public:
	bool isSameTree(TreeNode* p, TreeNode* q) {
		t1q.push(p);
		t2q.push(q);

		bool match = true;

		while (match)
		{
			if (t1q.empty() && t2q.empty())
				break;

			TreeNode *t1_node = t1q.front();
			t1q.pop();

			TreeNode *t2_node = t2q.front();
			t2q.pop();

			if ((!t1_node && !t2_node) || (t1_node && t2_node && (t1_node->val == t2_node->val))) // both nodes in the tree are NULL OR both nodes have values and they match
			{
				// if both nodes in the tree are NULL, no need to push node's children into queue, just continue with loop
				if (!t1_node && !t2_node)
					continue;

				// push children of node from t1 into t1's queue
				t1q.push(t1_node->left);
				t1q.push(t1_node->right);

				// push children of node from t2 into t2's queue
				t2q.push(t2_node->left);
				t2q.push(t2_node->right);
			}
			else
				match = false;
		}

		return match;
	}
};

int main(int argc, char *argv[])
{
	TreeNode *t1 = new TreeNode(1);
	TreeNode *node = new TreeNode(2);
	t1->left = node;
	node = new TreeNode(3);
	t1->right = node;

	TreeNode *t2 = new TreeNode(1);
	node = new TreeNode(2);
	t2->left = node;
	node = new TreeNode(3);
	t2->right = node;

	Solution *soln = new Solution();
	soln->isSameTree(t1, t2);

	return 0;
}