#include <iostream>
#include <string>
#include <queue>
#include <vector>

// Problem: Symmetric Tree

/* «ä¸ô:
*	(iterative)
*	Alex:
*
*	(recursive)
*	TBD
*/

// Bonus Points: Can you do it both iteratively and recursively?

using namespace std;

/*
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
	bool isSymmetric(TreeNode* root) {
		queue<TreeNode *> q;
		
		// the vector represents a certain level in the tree, it's contents should be identical to the front portion of the queue
		// (because as we process, the queue will keep on inserting child nodes of the nodes in the current level, but the vector won't)
		vector<TreeNode *> v;

		q.push(root);
		v.push_back(root);

		while (!q.empty())
		{
			// verify that this particular level of the tree is symmetrical via looking at the vector
			for (int i = 0, j = v.size() - 1; (i < j); (i++, j--))
			{
				// both pointers are NULL, symmetrical
				if (!v[i] && !v[j])
					continue;
				else if (v[i] && v[j] && (v[i]->val == v[j]->val))	// both pointers are valid and values match, symmetrical
					continue;
				else
					return false;	// any other case is unsymmetrical, return false
			}

			// clear the vector that represents the current level
			v.erase(v.begin(), v.end());
			
			// iterate the queue from the first element until its current length (without next level children), insert the children of the nodes in the queue into both the queue and the vector
			int q_length = q.size();
			for(int k = 0; k < q_length; k++)
			{
				TreeNode *tmp = q.front();
				if (tmp)
				{
					q.push(tmp->left);
					v.push_back(tmp->left);

					q.push(tmp->right);
					v.push_back(tmp->right);
				}
				q.pop();
			}
		}

		return true;
	}
};