// Problem: DI String Match

// Algorithm 1 (my own solution):
// Each letter in the DI string is actually describing the relationship
// between a pair of integers in the permutation array A, where A[i] = {0...N}, N=S.length()
// This is like in the "tree planting problem", we have 5 trees planted, therefore there are 4 gaps between the 5 trees.
// The DI string's letters represents the gaps, and the integers in array A represents the trees (or the heights of the trees)
// In order to plant trees with their heights following the DI string's rule, we could:
// 1. keep track of the next tallest and next shortest tree for planting
// 2. If we come across a 'D', that means the current tree should be taller than the next tree, so we pick the next tallest tree for planting
// 3. If we come across a 'I', that means the current tree should be shorter than the next tree, so we pick the next shortest tree for planting
// Do the above process until we've went through the entire DI string, and we would be left with a single last tree to plant,
// plant that and we're done.

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	vector<int> diStringMatch(string S) {
		int len = S.length();
		int next_max = len;  // the next biggest number available for use
		int next_min = 0;   // the next smallest number available for use

		vector<int> res;
		res.resize(len + 1);
		int i;
		for (i = 0; i<len; i++) {
			if (S[i] == 'I') {
				res[i] = next_min;
				next_min++;
			}
			else if (S[i] == 'D') {
				res[i] = next_max;
				next_max--;
			}
		}

		// by the end of the loop, next_min should equal next_max, 
		// so it doesn't matter which one we choose for insertion
		res[i] = next_min;

		return res;
	}
};