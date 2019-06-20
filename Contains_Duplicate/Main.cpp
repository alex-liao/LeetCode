// Problem: Contains Duplicate

// «ä¸ô: Use std::map to detect duplicates from array

#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	bool containsDuplicate(vector<int>& nums) {
		bool ret = false;
		map<int, int> occurrence;

		for (int i = 0; i < nums.size(); i++)
		{
			int val = nums[i];
			if (occurrence.find(val) == occurrence.end())
			{
				occurrence[val] = 1;
			}
			else
			{
				ret = true;
				break;
			}
		}

		return ret;
	}
};

int main(int argc, char *argv[])
{
	vector<int> input;
	Solution *soln = new Solution();
	cout << soln->containsDuplicate(input) << endl;

	return 0;
}