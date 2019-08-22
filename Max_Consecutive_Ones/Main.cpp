// Problem: Max Consecutive Ones

// Algorithm 1 (my own solution):
// TBD

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