#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// «ä¸ô:

// Problem: Maximum Subarray

// Solution from Grandyang
class Solution2 {
public:
	int maxSubArray(vector<int>& nums) {
		int res = INT_MIN, curSum = 0;
		for (int num : nums) {
			curSum = max(curSum + num, num);
			res = max(res, curSum);
		}
		return res;
	}
};

// Alex: Crappy O(n^2) solution
class Solution
{
private:
public:
	int maxSubArray(vector<int>& nums) {
		if (nums.empty())
			return 0;
		
		int max_sum = nums[0];

		for (int i = 0; i < nums.size(); i++)
		{
			int sum = 0;

			if (nums[i] <= 0)
			{
				if (nums[i] > max_sum)
					max_sum = nums[i];
				
				continue;
			}
			else
			{
				for (int j = i; j < nums.size(); j++)
				{
					sum = sum + nums[j];
					if (sum > max_sum)
						max_sum = sum;
				}
			}
		}

		return max_sum;
	}
};

int main(int argc, char *argv[])
{
	Solution2 *soln2 = new Solution2();
	vector<int> v = {-2,1,-3,4,-1,2,1,-5,4};

	cout << soln2->maxSubArray(v) << endl;

	return 0;
}