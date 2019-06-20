// Problem: Validate Binary Search Tree

// Thought Process:
// Method 1 (My own solution):
// 1. Flatten the tree into an array using in-order traversal
// 2. Check to see that the array is ordered
// Note: This algorithm only works if we are guaranteed that the tree has distinct values, as this algorithm cannot distinguish between trees like this:
//           20
//           /
//         20

// and
//           20
//             \
//              20
// This algorithm would consider both of these trees as valid BST, but by the definition of BST (left <= root < right), the 2nd tree would be considered as invalid
// But the problem statement for this question seems to tell us that left < root < right, so let's give this algorithm a try


// Method 2 (Ref: Cracking the coding interview 6e q4.5):
// Use the Min/Max Solution.
// Leverage the definition of BST: "all" left nodes <= current node < "all" right nodes
// 1. Use Recursion to traverse the tree
// 2. When we take the left path, we pass in a 'Max' value that equals to the current node's value
// 3. When we take the right path, we pass in a "Min' value that equals tot he current node's value
// 4. In this way, with every node that we come across, we get a range (Min,Max) for which the node's value must lie within in order for the BST validity check to pass
// 5. We update the values of Min/Max for each recursive call depending on the path we take (left or right)
// 6. If any node fails the checks, we stop and return false

#include <cstdlib>
#include <vector>
#include <queue>
#include <string>
#include <iostream>

#include "TreeNode.h"
#include "BinaryTreeHelper.h"

using namespace std;

// Definition for a binary tree node.
//struct TreeNode {
//    int val;
//    TreeNode *left;
//    TreeNode *right;
//    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
//};

// Solution 1
// Flatten binary tree to array
class Solution1 {
public:
	bool isValidBST(TreeNode* root) {
		vector<int> res;
		
		// flatten the tree into an array with in-order traversal
		isValidBSTRecursive(root, res);

		// check if the result vector is in order and strictly increasing
		int size = res.size();
		for (int i = 1; i < size; i++) {
			if (res[i] <= res[i-1]) {
				return false;
			}
		}

		return true;
	}

private:
	void isValidBSTRecursive(TreeNode* root, vector<int>& res) {
		if (!root) {
			return;
		}

		isValidBSTRecursive(root->left, res);
		res.push_back(root->val);
		isValidBSTRecursive(root->right, res);
	}
};

// Solution 2
// Min/Max solution
class Solution2 {
public:
	bool isValidBST(TreeNode* root) {
		long min = LONG_MIN, max = LONG_MAX;

		return isValidBSTRecursive(root, min, max);
	}

private:
	bool isValidBSTRecursive(TreeNode* root, long min, long max) {
		if (!root) {
			return true;
		}

		bool is_self_valid = false;
		bool is_left_valid = false;
		bool is_right_valid = false;
		
		// check self
		is_self_valid = ((root->val > min) && (root->val < max));
		if (!is_self_valid) {
			return false;
		}
		else {
			// check left subtree
			is_left_valid = isValidBSTRecursive(root->left, min, root->val);
			if (!is_left_valid) {
				return false;
			}
			// check right subtree
			is_right_valid = isValidBSTRecursive(root->right, root->val, max);
			if (!is_right_valid) {
				return false;
			}
		}

		return true;
	}
};

int main(void) {
	BinaryTreeHelper* bth = new BinaryTreeHelper();

	TreeNode* root = bth->buildTree({ 1,LONG_MIN,2,LONG_MIN,3,LONG_MIN,4 });
	Solution1* soln1 = new Solution1();

	cout << soln1->isValidBST(root) << endl;

	return 0;
}