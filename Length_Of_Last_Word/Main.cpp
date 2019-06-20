#include <string>
#include <iostream>

using namespace std;

// «ä¸ô:

// trap test cases:
// 1. " "
// 2. "a"
// 3. "a "

// Problem: Length of Last Word

class Solution {
public:
	int lengthOfLastWord(string s) {
		if (s.empty())
			return 0;

		int res = 0;
		string::iterator it = s.end() - 1;

		// trim away trailing spaces until we either meet a non-white space character, or that we've reached the beginning of the string
		while (*it == ' ' && it != s.begin())
		{
			it--;
		}

		// after trimming, if what we are left with is still a white space character, that means the string was full of white space chars and no words, return 0
		if (*it == ' ')
			return 0;

		for (; (((*it) != ' ') && it != s.begin()); it--)
		{
			res++;
		}
		if (it == s.begin() && ((*it) != ' '))
			res += 1;

		return res;
	}
};

int main(int argc, char *argv[])
{
	Solution *soln = new Solution();
	string s = " ";

	cout << soln->lengthOfLastWord(s);
	
	return 0;
}