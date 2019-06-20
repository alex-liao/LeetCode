#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

// 思路(Alex):
// 1. (錯誤思路)
// 把 s[0]...s[n/2] 的所有括弧通通 push 進 stack 裡
// 然後從 s[n/2]+1 到 s[n] 所碰到的每個字元，都從 stack 裡 pop 一個括弧出來看看有沒有 match
// 直到 string s 被檢查完為止

// 錯誤原因:
// 因為無意中假設了 括弧是 nested & symmetrical，所以碰到這種 case: "()[]{}" 的時候就會 fail

// 思路(Grandyang):
// 2. (正確思路):
// 只要是屬於左半邊的括弧，就把它 push 進 stack 裡
// 只要是碰到右半邊的括弧，就從 stack 裡 pop 出來檢查有沒有 match
// 如果沒有 match，則 return false
// 繼續如上檢查，直到 string s 被檢查完

class Solution {
private:
	stack<char> parentheses;
	
	bool isValidLeftParenthesis(char c)
	{
		if ((c == '(') || (c == '[') || (c == '{'))
			return true;
		else
			return false;
	}

	bool isValidRightParenthesis(char c)
	{
		if ((c == ')') || (c == ']') || (c == '}'))
			return true;
		else
			return false;
	}

public:
	bool isValid(string s)
	{
		// number of parentheses is not even, return false directly
		if (s.length() % 2 != 0)
			return false;

		for (int i = 0; i < s.length(); i++)
		{
			// non parenthesis character, return false directly
			if (!isValidLeftParenthesis(s[i]) && !isValidRightParenthesis(s[i]))
				return false;

			// push a valid left parenthesis into the stack
			if (isValidLeftParenthesis(s[i]))
				parentheses.push(s[i]);

			// found a valid right parenthesis
			if (isValidRightParenthesis(s[i]))
			{
				// but no item left in the stack, this is non-matching, return false;
				if (parentheses.empty())
				{
					return false;
				}
				else
				{
					// check for matching left parenthesis for each of the right parenthesis
					if (s[i] == ')')
					{
						if (parentheses.top() != '(')
							return false;
					}
					else if (s[i] == ']')
					{
						if (parentheses.top() != '[')
							return false;
					}
					else if (s[i] == '}')
					{
						if (parentheses.top() != '{')
							return false;
					}
					parentheses.pop();
				}
			}
		}

		return parentheses.empty() ? true : false;
	}
};

int main(int argc, char *argv)
{
	Solution *soln = new Solution();

	cout << soln->isValid("((") << endl;

	return 0;
}