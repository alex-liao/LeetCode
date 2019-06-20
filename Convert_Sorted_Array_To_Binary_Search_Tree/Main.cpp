// Problem: Convert Sorted Array to Binary Search Tree

// «ä¸ô:
// Method 1. (°Ñ¦Ò Grandyang)

// Method 2. Refer to Cracking the coding interview 5e question 4.3
// Basically, the idea is to take the middle value of the array as node, and pass the left portion of the array into
// the recursive call to be built as the left sub-tree, then pass the right portion of the array into the the recursive call
// to be built as the right-subtree


#include <string>
#include <iostream>
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

class Solution {
public:
	TreeNode* sortedArrayToBST(vector<int>& nums)
	{
		return sortedArrayToBSTRecursive(nums, 0, (nums.size() - 1));
	}

	TreeNode* sortedArrayToBSTRecursive(vector<int> &nums, int low, int high)
	{
		if (high < low)
			return nullptr;

		int mid = (low + high) / 2;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = sortedArrayToBSTRecursive(nums, low, (mid - 1));
		root->right = sortedArrayToBSTRecursive(nums, (mid + 1), high);

		return root;
	}
};

int main(int argc, char *argv)
{
	vector<int> array = {-10, -3, 0, 5, 9};

	Solution *soln = new Solution();
	TreeNode *root = soln->sortedArrayToBST(array);

	return 0;
}