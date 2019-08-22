// Problem: Max Consecutive Ones

// Algorithm 1 (my own solution):
// Use two variables, 'count' and 'max' to keep track of:
//     The number of 1s in a sequence of consecutive 1s
//     The maximum number of consecutive 1s we'v come across so far
// Then iterate through the input vector, counting the number of consecutive 1s as we go.
// When we encounter a 1, we increment count, when we encounter a 0, we check if current count
// is the new max, and update max if needed then reset count to 0.
// Finally, when the loop terminates, we check if current count is the new max again. This is because
// if the vector was ending with a group of ones, without this check, we would miss count the last group
// of consecutive 1s and it may be the max.

#include <vector>

using namespace std;

class Solution {
public:
	int findMaxConsecutiveOnes(vector<int>& nums) {
		unsigned int max = 0;
		unsigned int count = 0;

		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] == 1) {
				// count the ones...
				count++;
			}
			else {
				// met a 0, check if count is our new max, if so, update max
				if (count > max) {
					max = count;
				}
				// reset count
				count = 0;
			}
		}

		// if the end of the array is also a bunch of ones, need to check if its consecutive ones
		// is the new max
		if (count > max) {
			max = count;
		}

		return max;
	}
};