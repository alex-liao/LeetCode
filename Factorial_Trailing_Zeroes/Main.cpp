// Problem: Factorial Trailing Zeroes

// 思路:
// 1. (Wrong)
/* 
* Write a function that computes factorial of input 'n' and use div/mod to divide the result by 10 until we can no longer
* get a whole number
* 
* This is wrong because:
* When input 'n' gets too big, we cannot compute the factorial because the data type won't hold (overflow will occur)
*/

// 2. Grandyang
/*
* 这道题并没有什么难度，是让求一个数的阶乘末尾0的个数，也就是要找乘数中10的个数，
* 而10可分解为2和5，而我们可知2的数量又远大于5的数量，那么此题即便为找出5的个数。
* 仍需注意的一点就是，像25,125，这样的不只含有一个5的数字需要考虑进去
*
* Refer to here for further explainations:
* https://leetcode.com/problems/factorial-trailing-zeroes/discuss/196311/topic
*
* This is an even better explaination:
* https://leetcode.com/problems/factorial-trailing-zeroes/discuss/52373/Simple-CC%2B%2B-Solution-(with-detailed-explaination)
*
* Alex 註解: 我們知道 2 的數量遠大於5的數量的原因是因為，在把某數字 factorize 的過程中，其因數有較多可以被2繼續分解。
* e.g.  60 = 2 * 30 = 2 * 3 * 10 = 2 * 3 * (2 * 5) = 2^2 * 3 * 5
* 所以問題可以簡化成為"尋找5的個數"，因為 5 要跟 2 互乘 才會得到 10，才會有 trailing 0
*/

#include <iostream>

using namespace std;

class Solution {
public:
	int trailingZeroes(int n) {
		// a counter for counting how many 5s we came across
		int count = 0;

		// Here's the elegant part of the algorithm.
		// With each iteration, we're actually finding how many multiples of 5^x (x is the iteration count, from 0 to k) there is between 0 and the input value.
		// This is achieved by repeatedly dividing the input by 5 at the end of each iteration. (input/5, input/5/5 which is the same as input/25, input/5/5/5, which is the same as input/125...etc)

		// e.g. For n = 125, we try to find:
		// In the 1st iteration: How many multiples of 5 there is between 0 and 125. (5, 10, 15, 20, 25, 30....125). Each of these multiples of 5 gives us a 5 in our factorial computation
		// In the 2nd iteration: How many multiples of 25 there is between 0 and 125. (25, 50, 75, 100, 125). Each of these multiples of 25 gives us an additional 5 in our factorial computation
		// In the 3rd iteration: How many multiples of 125 there is between 0 and 125. (just 125). Each of these multiples of 125 gives us yet another 5 in our factorial computation
		while (n > 0) {
			count += n/5;
			n /= 5;
		}

		return count;
	}
};

int main(void) {
	Solution* soln = new Solution();
	cout << soln->trailingZeroes(1808548329) << endl;

	return 0;
}