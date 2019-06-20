#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Alex:
// �o�D�ڨS�Ѧ��\�A�ڭ쥻�����D�����o�ѵ��O�@�˪��A���S�ন�\�� code �g�X��
// �ѵ��q�o�̴M�o: http://www.cnblogs.com/grandyang/p/4125510.html

// ���D���:



// �ۤv�m��é���g�@��

class Solution
{
public:
	bool isPalindrome(int x)
	{
		if (x < 0 || ((x % 10 == 0) && x != 0))
			return false;

		int div = 1;

		// ��X���h�֦��
		while ((x / div) >= 10)
			div *= 10;

		while (x > 0)
		{
			int left = x / div;
			int right = x % 10;
			if (left != right)
				return false;
			x = (x % div) / 10;
			div /= 100;
		}

		return true;
	}
};

int main(int argc, char *argv[])
{
	Solution *soln = new Solution();
	
	cout << soln->isPalindrome(12321) << endl;
	cout << soln->isPalindrome(11111) << endl;
	cout << soln->isPalindrome(1234) << endl;

	return 0;
}