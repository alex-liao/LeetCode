// Problem: Excel Sheet Column Title

// Algorithm 1 (my own solution):
// TBD, although this problem looks like a base 26 numeral system, but there's
// actually something tricky about this problem that makes it different to 
// ordinary "numeral system" conversion problems.
// 1. There's no '0' in this problem, the minimum value is 1, and max is unlimited.
// This would affect the % operation, when we encounter multiples of 26.
// 2. The number 26 actuall occurrs in the problem. e.g. 26 maps to 'Z'. In ordinary
// numeral system conversion problems, the number for the numeral system don't occurr.
// e.g. in decimal, we only have 0 ~ 9 and no 10. In hexadecimal, we only have 0 ~ 15 and no 16.

// The basic idea is still to use repetitive mod&div, treating this problem like a ordinary
// base 26 numeral system problem. However, there's a trick at the 'div' stage, where the
// number needs to be subtracted by 1 before div. I worked this out by experimenting with different
// input test cases such as 27, 28, 52, 701, but not really knowing what the -1 really represents.

#include <string>

using namespace std;

class Solution {
public:
	string convertToTitle(int n) {
		char map[26] = { 'Z', 'A', 'B', 'C', 'D', 'E',
			'F', 'G', 'H', 'I', 'J',
			'K', 'L', 'M', 'N', 'O',
			'P', 'Q', 'R', 'S', 'T',
			'U', 'V', 'W', 'X', 'Y' };

		string res = "";
		while (n > 0) {
			if (n < 26) {
				res.insert(res.begin(), map[n]);
				break;
			}
			int rem = n % 26;
			res.insert(res.begin(), map[rem]);
			n = (n - 1) / 26;
		}

		return res;
	}
};