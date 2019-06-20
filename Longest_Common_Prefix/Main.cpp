#include <string>
#include <vector>
#include <iostream>

using namespace std;

// ��� (Alex):
// �����h�j��A�~�h�L�a�j��ΨӦs���C�� string �����Ģ��A��2, ��3...��n �Ӧr��
// �C�]�@���~�h�j��ɡA���h�j��Ψ�¶ vector �̭����C���r��A�p���@�ӳo�˪��j�鵲�c�N�|�ܦ�
// �~��]��1���ɷ|�ݩҦ� vector ���� string ����2�Ӧr���A
// �~��]��2���ɷ|�ݩҦ� vector ���� string ����2�Ӧr��
// �̦������A���즳�Y�� string �w�g�]����� (null character) �άO longest common prefix �_��

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		string res = "";

		int i = 0;

		// �Ψӷ�@�s���� n �� �r�����j��
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