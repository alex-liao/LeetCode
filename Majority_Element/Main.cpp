// Problem: Majority Element

// «ä¸ô:


#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	int majorityElement(vector<int>& nums)
	{
		int res = 0;

		map<int, int> occurrences;

		for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++)
		{
			// the number does not exist in the map yet, insert its occurrence as 1
			int key = *it;
			if (occurrences.find(key) == occurrences.end())
			{

				occurrences[key] = 1;
			}
			else // increment the occurrence count by one
			{
				occurrences[key] += 1;
			}
		}

		int threshold = floor(nums.size() / 2);
		
		// iterate through the map, looking for the majority element
		for (map<int, int>::iterator it = occurrences.begin(); it != occurrences.end(); it++)
		{
			if (it->second > threshold)
				res = it->first;
		}

		return res;
	}

private:
};

int main(int argc, char *argv[])
{
	Solution *soln = new Solution();
	
	vector<int> input;
	input.push_back(2);
	input.push_back(2);
	input.push_back(1);
	input.push_back(1);
	input.push_back(1);
	input.push_back(2);
	input.push_back(2);

	cout << soln->majorityElement(input) << endl;

	return 0;
}