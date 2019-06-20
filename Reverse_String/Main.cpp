#include <string>

// Problem: Reverse String

// 思路:

using namespace std;

class Solution {
public:
	string reverseString(string s) {
		string res = "";

		for (string::iterator it = s.end() - 1; it >= s.begin(); it--)
		{
			res += (*it);
		}

		return res;
	}
};

