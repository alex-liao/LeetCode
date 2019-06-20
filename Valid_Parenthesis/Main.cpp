#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>

using namespace std;

// ���(Alex):
// 1. (���~���)
// �� s[0]...s[n/2] ���Ҧ��A���q�q push �i stack ��
// �M��q s[n/2]+1 �� s[n] �ҸI�쪺�C�Ӧr���A���q stack �� pop �@�ӬA���X�Ӭݬݦ��S�� match
// ���� string s �Q�ˬd������

// ���~��]:
// �]���L�N�����]�F �A���O nested & symmetrical�A�ҥH�I��o�� case: "()[]{}" ���ɭԴN�| fail

// ���(Grandyang):
// 2. (���T���):
// �u�n�O�ݩ󥪥b�䪺�A���A�N�⥦ push �i stack ��
// �u�n�O�I��k�b�䪺�A���A�N�q stack �� pop �X���ˬd���S�� match
// �p�G�S�� match�A�h return false
// �~��p�W�ˬd�A���� string s �Q�ˬd��

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