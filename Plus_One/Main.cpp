#include <vector>
#include <iostream>

using namespace std;

// Problem: Plus One

// 思路:

class Solution {
public:
	vector<int> plusOne(vector<int>& digits) {
		// 把問題轉成 integer + 0 + carry=1, 這樣的話就可以不用特例處理。我把問題中的 plus one 變成 carry = 1 的形式，因此每次迴圈都可以當作 digit + carry(有或無) 來處理。
		int sum = 0, carry = 1;

		// 從最低位數，到最高位數
		for (vector<int>::iterator it = (digits.end() - 1); it >= digits.begin(); it--)
		{
			sum = (*it) + carry;
			// 每位數的和，是 (digit + carry) mod 10 後的結果
			(*it) = sum % 10;
			// 進位則是 (/ 10) 後的結果
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