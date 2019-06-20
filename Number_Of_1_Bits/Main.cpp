// Problem: Number of 1 Bits

// Thought process:
// Method 1 (My solution):
// The given input will be treated as a decimal int. E.g. an input of "1011" will actually be treated as 11.
// Use repeat mod & div (by 2) process to count the number of times a remainder of '1' occurred. Stop when the quotient from 'div' becomes 0

#include <stdint.h>

using namespace std;

class Solution {
public:
	int hammingWeight(uint32_t n) {
		int count = 0;

		while (n) {
			count += n % 2;
			n /= 2;
		}

		return count;
	}
};