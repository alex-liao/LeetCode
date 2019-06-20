#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	int strStr(string haystack, string needle) {
		if (!needle.length())
			return 0;

		// if haystack is shorter than needle, no need to search anymore
		if (haystack.length() < needle.length())
			return -1;

		// let i be the index for needle, j be the index for haystack
		int i = 0, j = 0;
		int found = -1;

		while (j < haystack.length())
		{
			if (i == needle.length())
			{
				break;
			}

			if (haystack[j] != needle[i])
			{
				// 1. we have not yet got a match, so we move along with the search in haystack
				if (found == -1)
				{
					j++;
				}
				// 2. we are in the middle of a match, but the match failed
				//    so we set haystack's index to the next character and we set found back to -1 and we set needle's index back to 0
				else
				{
					j = found + 1;
					found = -1;
					i = 0;
				}
			}
			else
			{
				if (found == -1)
				{
					found = j;
				}
				i++;
				j++;
			}
		}

		if (i == needle.length())
			return found;
		else
			return -1;
	}
};

int main(int argc, char *argv[])
{
	Solution soln = Solution();
	cout << soln.strStr("mississippi", "issipi") << endl;
	cout << soln.strStr("hello", "cat") << endl;
	cout << soln.strStr("hello", "lo") << endl;

	return 0;
}