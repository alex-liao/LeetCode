#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 思路 (Alex):
// 用雙層迴圈，外層無窮迴圈用來存取每條 string 內的第１，第2, 第3...第n 個字元
// 每跑一次外層迴圈時，內層迴圈用來繞 vector 裡面的每條字串，如此一來這樣的迴圈結構就會變成
// 外圈跑第1輪時會看所有 vector 內的 string 的第2個字元，
// 外圈跑第2輪時會看所有 vector 內的 string 的第2個字元
// 依此類推，直到有某條 string 已經跑到尾端 (null character) 或是 longest common prefix 斷掉

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string res = "";

		int i = 0;

		// 用來當作存取第 n 個 字元的迴圈
		while (true)
		{
			// empty vector, return empty string directly
			if (!strs.size())
				return "";

			// pick the character we are going to use for comparison from the first string in the vector
			char current_char = strs[0][i];
			
			// if the first string in the vector is used up already, then return the current longest common prefix we've got
			if (current_char == '\0')
				return res;

			unsigned int j = 0;
			for (; j < strs.size(); j++)
			{
				// if on of the strings in the vector failed to match, or if the string has reached its end, then return what we've got so far
				if (strs[j][i] != current_char || strs[j][i] == '\0')
				{
					return res;
				}
			}
			
			// if we had successfully compared through all the strings in the vector, that means we can add the current character to be part of longest common prefix
			if (j == strs.size())
				res += current_char;

			i++;
		}

		return res;
	}
};

int main(int argc, char *argv[])
{
	Solution *soln = new Solution();
	vector<string> v;
	//v.push_back("dog");
	//v.push_back("racecar");
	//v.push_back("car");
	cout << soln->longestCommonPrefix(v) << endl;

	return 0;
}