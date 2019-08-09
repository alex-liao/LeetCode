// Problem: Longest Palindromic Substring

// Algorithm:
// Method 1 (My own solution): Time Limit Exceeded
// 1. Find all the substrings of the given input string
// 2. Check if a substring is palindromic, if it is, calculate it's length
// 3. Keep track of the longest palindromic substring and return when computation is done

// Method 2 (Ref: Grandyang):
// 1. 

#include <string>
#include <iostream>

using namespace std;

// Time Limit Exceeded
class Solution {
public:
	string longestPalindrome(string s) {
		int i = 0;
		int len = s.length();
		int longest = -1;
		string res = "";

		while (i < len) {
			int j = i;
			while (j < len) {
				string substr = string(s, i, (j - i + 1));
				if (isPalindromic(substr)) {
					int substr_len = substr.length();
					if (substr_len > longest) {
						longest = substr_len;
						res = substr;
					}
				}
				j++;
			}
			i++;
		}

		return res;
	}

private:
	bool isPalindromic(string s) {
		if (s.length() == 1) {
			return true;
		}

		int i = 0, j = s.length() - 1;
		
		while (i < j) {
			if (s[i] != s[j]) {
				return false;
			}
			i++;
			j--;
		}

		return true;
	}
};

// Grandyang's solution
class Solution2 {
public:
	string longestPalindrome(string s) {
	}
};

int main(void) {
	string s = "heh";

	int i = 0;
	int j = s.length() - 1;

	if (s[++i] == s[--j]) {
		cout << "yay" << endl;
	}
	else {
		cout << "nay" << endl;
	}

	return 0;
}