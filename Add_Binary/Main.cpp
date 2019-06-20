#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

// Problem: Add Binary

// ���:
// �Ψ�ӫ��СA�q��� string �� least significant bit �}�l iterate
// ��C�� iteration�A��X sum �M carry
// �p���`�������� string �� iterate ���Y����.

class Solution {
public:
	string addBinary(string a, string b) {
		string res = "";
		int idx_a = a.size() - 1, idx_b = b.size() - 1, carry = 0;

		while (idx_a >= 0 || idx_b >= 0)
		{
			int digit_a = (idx_a >= 0) ? (a[idx_a] - '0') : 0;
			int digit_b = (idx_b >= 0) ? (b[idx_b] - '0') : 0;
			int tmp = (digit_a + digit_b + carry);
			int sum = tmp % 2;
			res = to_string(sum) + res;
			carry = tmp / 2;
			idx_a--;
			idx_b--;
		}
		
		if (carry)
			res = "1" + res;

		return res;
	}
};

int main(int argc, char *argv[])
{
	Solution *soln = new Solution();
	cout << soln->addBinary("1010", "1011");
	
	return 0;
}