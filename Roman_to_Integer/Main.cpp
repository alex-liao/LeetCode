#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// input is guaranteed to be from 1 ~ 3999

// ¸ÑÃD«ä¸ô:


class Solution {
public:
	int romanToInt(string s)
	{
		int res = 0;
		
		unordered_map<char, int> m{ {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
		
		for (int i = 0; i < s.length(); i++)
		{
			// check if is last digit, if so, add and return result
			if (s[i + 1] == '\0')
			{
				res += m[s[i]];
			}
			else
			{
				// check if the next_number > current_number, if so, then current number should be subtracted not added to the result
				if (m[s[i + 1]] > m[s[i]])
				{
					res -= m[s[i]];
				}
				else // otherwise, the number should just be added to the result
				{
					res += m[s[i]];
				}
			}
		}

		return res;
	}
};

int main(int argc, char *argv[])
{
	Solution *soln = new Solution();
	cout << soln->romanToInt("MCMXCIV") << endl;

	return 0;
}