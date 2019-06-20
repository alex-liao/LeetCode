#include <vector>
#include <iostream>

using namespace std;

// Problem: Plus One

// ���:

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		// ����D�ন integer + 0 + carry=1, �o�˪��ܴN�i�H���ίS�ҳB�z�C�ڧ���D���� plus one �ܦ� carry = 1 ���Φ��A�]���C���j�鳣�i�H��@ digit + carry(���εL) �ӳB�z�C
		int sum = 0, carry = 1;

		// �q�̧C��ơA��̰����
		for (vector<int>::iterator it = (digits.end() - 1); it >= digits.begin(); it--)
		{
			sum = (*it) + carry;
			// �C��ƪ��M�A�O (digit + carry) mod 10 �᪺���G
			(*it) = sum % 10;
			// �i��h�O (/ 10) �᪺���G
			carry = sum / 10;
		}

		if (carry)
			digits.insert(digits.begin(), 1);

		return digits;
	}
};

int main(int argc, char *argv[])
{
	Solution *soln = new Solution();
	vector<int> v = {1,9,9};

	soln->plusOne(v);

	for (int n : v)
		cout << n << ",";

	cout << endl;

	return 0;
}