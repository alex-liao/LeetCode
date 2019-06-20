// Problem: Excel Sheet Column Number

// «ä¸ô:

#include <string>
#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
	Solution()
	{
		char_to_int['A'] = 1;
		char_to_int['B'] = 2;
		char_to_int['C'] = 3;
		char_to_int['D'] = 4;
		char_to_int['E'] = 5;
		char_to_int['F'] = 6;
		char_to_int['G'] = 7;
		char_to_int['H'] = 8;
		char_to_int['I'] = 9;
		char_to_int['J'] = 10;
		char_to_int['K'] = 11;
		char_to_int['L'] = 12;
		char_to_int['M'] = 13;
		char_to_int['N'] = 14;
		char_to_int['O'] = 15;
		char_to_int['P'] = 16;
		char_to_int['Q'] = 17;
		char_to_int['R'] = 18;
		char_to_int['S'] = 19;
		char_to_int['T'] = 20;
		char_to_int['U'] = 21;
		char_to_int['V'] = 22;
		char_to_int['W'] = 23;
		char_to_int['X'] = 24;
		char_to_int['Y'] = 25;
		char_to_int['Z'] = 26;
	}

	int titleToNumber(string s)
	{
		int res = 0;

		for (int i = (s.length() - 1), iteration = 0; i >= 0; i--, iteration++)
		{
			res = res + (char_to_int[s[i]] * pow(26, iteration));
		}

		return res;
	}

private:
	map<char, int> char_to_int;
};

int main(int argc, char *argv[])
{
	Solution *soln = new Solution();

	string title = "ZY";

	cout << soln->titleToNumber(title) << endl;;

	return 0;
}