// Problem: Squares Of A Sorted Array

// «ä¸ô: 

#include <string>
#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& A)
	{
		map<int, int> frequency;
		vector<int> output;

		// first iterate through the input vector, tally the frequencies of all the values
		for (vector<int>::iterator it = A.begin(); it != A.end(); it++)
		{
			int abs_val;

			// turn negatives to positives via abs()
			if (*it < 0)
			{
				abs_val = abs(*it);
			}
			else
			{
				abs_val = *it;
			}

			// increment the frequency map
			if (frequency.find(abs_val) == frequency.end())
			{
				frequency[abs_val] = 1;
			}
			else // increment the frequency count
			{
				frequency[abs_val] += 1;
			}
		}

		// iterate through the frequency map (which is ordered) and push the squared results into the output vector
		for (map<int, int>::iterator it = frequency.begin(); it != frequency.end(); it++)
		{
			int val = it->first, freq = it->second;
			unsigned int squared = val * val;
			for (int i = freq; i > 0; i--)
			{
				output.push_back(squared);
			}
		}

		return output;
	}
};

int main()
{
	vector<int> input;
	input.push_back(-4);
	input.push_back(-1);
	input.push_back(0);
	input.push_back(3);
	input.push_back(10);

	Solution *soln = new Solution();
	soln->sortedSquares(input);

	return 0;
}