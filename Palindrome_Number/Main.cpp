#include <iostream>
#include <string>
#include <cmath>

using namespace std;

// Alex:
// 這題我沒解成功，我原本的解題思路跟這解答是一樣的，但沒能成功把 code 寫出來
// 解答從這裡尋得: http://www.cnblogs.com/grandyang/p/4125510.html

// 解題思路:



// 自己練習矇眼寫一次

class Solution
{
public:
	bool isPalindrome(int x)
	{
		if (x < 0 || ((x % 10 == 0) && x != 0))
			return false;

		int div = 1;

		// 找出有多少位數
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