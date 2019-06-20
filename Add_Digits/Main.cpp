// Problem: Add Digits

// «ä¸ô:
// Method 1:
// Use 'mod + div' method to go through each of the digits and sum them up. Stop when div by 10 gives 0

// Follow up: Can you do it without loop/recursion in O(1) runtime?
// Method 2: (Couldn't think of it myself, refer to discussions section. See "Digital Root - Congruence formula" on wikipedia)
// 

#include <iostream>

class Solution {
public:
	int addDigits(int num) {
		// the input for each iteration
		int input = num;

		// div the input by 10, if quotient is > 0, we have more than 1 digit, otherwise we only have 1 digit
		bool is_single_digit = input / 10 ? false : true;

		// outer loop for determining when we should stop
		while (!is_single_digit) {
			// inner loop for going through summing up the individual digits
			int digits_sum = 0;
			
			while (input / 10) {
				digits_sum += (input % 10);
				input = input / 10;
			}
			
			// add the final MSB digit
			digits_sum += input;

			input = digits_sum;

			if (digits_sum < 10) {
				is_single_digit = true;
			}
		}

		return input;
	}
};

int main(void) {
	
}