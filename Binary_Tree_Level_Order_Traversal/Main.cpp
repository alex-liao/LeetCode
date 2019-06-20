// Problem: Binary Tree Level Order Traversal

// «ä¸ô: 
// (Iterative)
// I think this is just ordinary BFS algorithm...?

// (Recursive)
// ?

#include <queue>
#include <vector>

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

// Iterative Solution
class Solution {
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		queue<TreeNode *> q;

		q.push(root);

		while (!q.empty())
		{
			vector<int> level;
			int q_size = q.size();
			for (int i = 0; i < q_size; i++)
			{
				TreeNode *node = q.front();
				q.pop();

				if (node)
				{
					level.push_back(node->val);
					if (node->left)
						q.push(node->left);
					if (node->right)
						q.push(node->right);
				}
			}
			if (!level.empty())
				res.push_back(level);
		}

		return res;
	}
};

// Recursive Solution
class SolutionRecursive
{
public:
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> res;
		int level = 0;
		levelOrderRecursion(root, level, res);
		return res;
	}

private:
	void levelOrderRecursion(TreeNode *root, int level, vector<vector<int>> &res)
	{
		if (!root)
			return;
		
		if (res.size() == level)
			res.push_back({});

		res[level].push_back(root->val);
		
		if (root->left)
			levelOrderRecursion(root->left, level + 1, res);
		if (root->right)
			levelOrderRecursion(root->right, level + 1, res);
	}
};

int main()
{
	TreeNode *root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	TreeNode *tmp = root->left;
	tmp->left = new TreeNode(4);
	tmp->right = new TreeNode(5);

	tmp = root->right;
	tmp->left = new TreeNode(6);
	tmp->right = new TreeNode(7);

	SolutionRecursive *soln = new SolutionRecursive();
	soln->levelOrder(root);
}