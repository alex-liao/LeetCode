// Problem: Kth Smallest Element in a BST

// Algorithm:
// Method 1 (My own solution):
// 1. Flatten the BST to an array using in-order traversal
// 2. Access the [k-1] element in the array to get the kth smallest element

// Method 2 (My own solution):
// Similar to Method 1, but not using a vector. Instead, return the TreeNode pointer
// to the kth smallest element directly

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

// Solution 1
class Solution1 {
public:
	int kthSmallest(TreeNode* root, int k) {
		vector<int> bst_array;
		kthSmallestRecursive(root, bst_array);
		return bst_array[k - 1];
	}

private:
	void kthSmallestRecursive(TreeNode* root, vector<int>& bst_array) {
		if (!root) {
			return;
		}
		kthSmallestRecursive(root->left, bst_array);
		bst_array.push_back(root->val);
		kthSmallestRecursive(root->right, bst_array);
	}
};

// Solution 2
class Solution2 {
public:
	int kthSmallest(TreeNode* root, int k) {
		int counter = 0;
		TreeNode* kth_smallest = kthSmallestRecursive(root, k, counter);

		return kth_smallest->val;
	}

private:
	TreeNode* kthSmallestRecursive(TreeNode* root, int k, int& counter) {
		// base case
		if (!root) {
			return nullptr;
		}

		TreeNode* found = nullptr;
		// check left child
		found = kthSmallestRecursive(root->left, k, counter);
		if (found) {
			return found;
		}
		// check self node
		counter++;
		if (counter == k) {
			return root;
		}
		// check right child
		found = kthSmallestRecursive(root->right, k, counter);
		if (found) {
			return found;
		}

		return nullptr;
	}
};