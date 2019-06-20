#include <vector>
#include <iostream>

using namespace std;

// Problem: Search Insert Position

// «ä¸ô:
//

class Solution {
public:
	int searchInsert(vector<int>& nums, int target) {
		int i = 0;

		if (nums.empty())
			return i;

		for (; i < nums.size(); i++)
		{
			if (nums[i] < target)
				continue;
			else
				return i;
		}

		return i;
	}
};