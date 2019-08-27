// Problem: Missing Number

// Algorithm 1 (my own solution):
// Using Gaussian Formula ((1 + N) * N) /2

// Algorithm 2 (Ref Grandyang):

#include <vector>

using namespace std;

// Algorithm 1
class Solution {
public:
	int missingNumber(vector<int>& nums) {
		size_t size = nums.size();

		// the supposed sum if no elem was missing
		unsigned int supposed_sum = (1 + size) * size / 2;
		unsigned int actual_sum = 0;

		// find the sum of elems in the array
		for (auto it = begin(nums); it != end(nums); it++) {
			actual_sum += *it;
		}

		return supposed_sum - actual_sum;
	}
};

// Algorithm 2 (Ref Grandyang):
// Using bitwise manipulation
// If we XOR all the elements in the input array with the complete array (no number is missing), then we would get:
// 0 XOR 0 XOR 1 XOR 1 XOR ... XOR n XOR n XOR missing#
//
// by XOR's property that:
// 1. XOR is both commutative and associative
// 2. A XOR A = 0
// 3. 0 XOR A = A
// The above XOR operations would result in:
// 0 XOR missing# => missing#

class Solution {
public:
	int missingNumber(vector<int>& nums) {

	}
};