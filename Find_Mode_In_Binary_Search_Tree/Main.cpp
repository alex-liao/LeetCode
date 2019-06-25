// Problem: Find Mode In Binary Search Tree

// Algorithms:
// Method 1 (My own solution, trivial):
// Traverse the tree using whichever way you like, use a <map> to tally the occurrence frequencies
// for the node values and finally iterate through the map to find the max occurrence count

// Method 2 (Follow up: Without using extra space):
// Ref: Grandyang

#include "BinaryTreeHelper.h"
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> findMode(TreeNode* root) {
		map<int, int> freq;
		vector<int> res;

		// traverse the tree first
		findModeRecursive(root, freq);

		// now find what is the maximum occurrence count
		int max = -1;
		for (map<int, int>::iterator it = freq.begin(); it != freq.end(); it++) {
			if (it->second > max) {
				max = it->second;
			}
		}

		// 2nd pass, now find and insert all the modes into output vector
		for (map<int, int>::iterator it = freq.begin(); it != freq.end(); it++) {
			if (it->second == max) {
				res.push_back(it->first);
			}
		}

		return res;
	}

	// In-order tree traversal, for each node value, sum up how many times it occurred
	void findModeRecursive(TreeNode* root, map<int, int>& freq) {
		if (!root)
			return;

		findModeRecursive(root->left, freq);
		if (freq.find(root->val) != freq.end()) {
			freq[root->val] += 1;
		}
		else {
			freq[root->val] = 1;
		}
		findModeRecursive(root->right, freq);
	}
};

class Solution2 {
public:
	vector<int> findMode(TreeNode* root) {
		vector<int> res;
		
		// points to previous node, initialised to NULL
		TreeNode* prev = nullptr;
		
		// keep track of the max occurrence count so far
		int max_occurrence = 0;

		// keep track of the occurrence count for the current node value
		int occurrence = 0;

		// In-Order recursive traversal
		findModeRecursive(root, res, prev, max_occurrence, occurrence);

		return res;
	}

private:
	// In-Order traversal
	void findModeRecursive(TreeNode* root, vector<int>& res, TreeNode*& prev, int& max_occurrence, int& occurrence) {
		// base case
		if (!root) {
			return;
		}

		findModeRecursive(root->left, res, prev, max_occurrence, occurrence);

		if (!prev) {
			// this is the first node we've came across
			occurrence = 1;
			max_occurrence = occurrence;
			res.push_back(root->val);
		}
		else {
			// still the same node value
			if (root->val == prev->val) {
				// increment its occurrence count first
				occurrence++;
				if (occurrence >= max_occurrence) {
					if (occurrence > max_occurrence) {
						// we have a new most occurring candidate, reset max counter and flush vector
						max_occurrence = occurrence;
						res.clear();
						res.push_back(root->val);
					}
					else { // occurrence == max_occurrence
						// a new and equally frequently occurring candidate, add it to vector
						res.push_back(root->val);
					}
				}
			}
			else { // a new node value
				// reset occurrence counter
				occurrence = 1;
				// the following case represents when we've only came across a max_occurrence of 1
				// and we are constantly getting to new node values. This is the only case we need
				// to handle here. The other possibilities are handled in the 'still the same node value'
				// scenario
				if (occurrence == max_occurrence) {
					res.push_back(root->val);
				}
			}
		}

		// set 'prev' to point to current node before we move on to next node
		prev = root;

		findModeRecursive(root->right, res, prev, max_occurrence, occurrence);
	}
};

int main(void) {
	BinaryTreeHelper bth;

	TreeNode* root = bth.buildTree({ 1,LONG_MIN,2,2 });
	Solution2* soln2 = new Solution2();
	vector<int> res = soln2->findMode(root);

	for (vector<int>::iterator it = res.begin(); it != res.end(); it++) {
		cout << *it << endl;
	}

	return 0;
}