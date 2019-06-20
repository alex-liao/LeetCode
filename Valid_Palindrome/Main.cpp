// Problem: Valid Palindrome

// «ä¸ô: 

#include <string>
#include <iostream>
#include <cctype>

using namespace std;

class Solution {
public:
	bool isPalindrome(string s) {
		int i = 0, j = s.length() - 1;
		
		while (i < j)
		{
			if (!isalnum(s[i]))
			{
				i++;
				continue;
			}

			if (!isalnum(s[j]))
			{
				j--;
				continue;
			}

			if (tolower(s[i]) != tolower(s[j]))
			{
				return false;
			}

			i++;
			j--;
		}

		return true;
	}
};

int main()
{
	Solution *soln = new Solution();
	string test_str = "race a car";

	cout << soln->isPalindrome(test_str) << endl;

	return 0;
}