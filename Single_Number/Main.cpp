#include <vector>

// Problem: Single Number

// Note: Your algorithm should have Linear time complexity

// 思路: 想不出 linear runtime solution, 參考網路: http://www.powerxing.com/leetcode-single-number/

// 因为A XOR A = 0，且XOR运算是可交换的，于是，对于实例{ 2,1,4,5,2,4,1 }就会有这样的结果：
// (2 ^ 1 ^ 4 ^ 5 ^ 2 ^ 4 ^ 1) = > ((2 ^ 2) ^ (1 ^ 1) ^ (4 ^ 4) ^ (5)) = > (0 ^ 0 ^ 0 ^ 5) = > 5
// 就把只出现了一次的元素(其余元素均出现两次)给找出来了！

using namespace std;

class Solution {
public:
	int singleNumber(vector<int>& nums) {
		int res = 0;

		for (int n : nums)
			res ^= n;

		return res;
	}
};