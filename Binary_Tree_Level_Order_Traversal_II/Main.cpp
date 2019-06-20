// Problem: Binary Tree Level Order Traversal II

// 思路: 
// 跟 Binary Tree Level Order Traversal 同樣的 tree traversal 方式，只是在儲存時，每次都 insert 在 vector 的 begin 位置便可。

#include <queue>
#include <vector>

using namespace std;

// There are iterative and recursive solutions

/**
* Definition for a binary tree node.
*/
struct TreeNode
{
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Iterative, adapted from "Binary Tree Level Order Traversal"
class SolutionIterative
{
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {
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
			{
				vector<vector<int>>::iterator it = res.begin();
				res.insert(it, level);
			}
		}

		return res;
	}
};

// Recursive solution
class SolutionRecursive {
public:
	vector<vector<int>> levelOrderBottom(TreeNode* root) {

	}
};

int main(int argc, char *argv[])
{
	return 0;
}