// Problem: String to Integer (atoi)

// Thought process:
// Iterate to the first non-whitespace character in the given string, check if it is a plus/minus sign or if it a numerical char.
// If yes, continue parsing, if not return 0 (no valid conversion). When we are done, check for +/-(2^31 - 1) boundary.
// As for how to check for overflow, this is a bit tricky...I am still thinking about it and going to try it out as I code.

#include <iostream>
#include <string>
#include <cstdint>

using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		// check for validity for conversion
		str = build_numeral_string(str);
		
		// if not valid, return 0
		if (str.empty()) {
			return 0;
		}

		// check for signed integer overflow
		if (is_integer_overflow(str)) {
			if (str[0] == '+') {
				// positive overflow
				return INT_MAX;
			}
			else {
				// negative overflow
				return INT_MIN;
			}
		}

		// finally, convert the valid string to int
		bool is_negative = str[0] == '-' ? true : false;
		str = str.substr(1);	// drop the sign now
		
		int mul = is_negative ? -1 : 1;
		int res = 0;

		// working backwards on the string
		for (int i = (str.length() - 1); i >= 0; i--) {
			res += mul * (str[i] - '0');
			
			// ALERT!: only do the 10x multiply if we have not yet reached the most significant digit
			// otherwise at the most significant digit, we will get runtime error because the multiplier itself overflows
			if (i > 0) {
				mul *= 10;
			}
		}

		return res;
	}

private:
	// function for checking if string is valid for conversion.
	// If so, just return the valid portion (sign & numerical) of the string, otherwise return empty string.
	string build_numeral_string(string str) {
		string res = "";
		bool is_negative = false;

		// get to first non-whitespace char
		int i = 0;
		while (str[i] == ' ') {
			i++;
		}

		// check first non-whitespace char
		if (str[i] != '+' && str[i] != '-' && !is_numerical_char(str[i])) {
			return "";
		}

		// check for sign (need to include '+' here as well because there are test cases such as "+1")
		if (str[i] == '-' || str[i] == '+') {
			is_negative = str[i] == '-' ? true : false;
			i++;
		}

		// check for numerical-ness
		if (!is_numerical_char(str[i])) {
			// not numerical, return empty string
			return "";
		}
		else {
			// is numerical, and is positive, add a '+' sign first
			if (is_negative) {
				res += '-';
			}
			else {
				// otherwise, add a '-' sign
				res += "+";
			}

			// skip leading zeros, if any
			while (str[i] == '0') {
				i++;
			}

			// start building the numeral string
			while (is_numerical_char(str[i])) {
				res += str[i];
				i++;
			}

			// done with building the numeral string
			return res;
		}
	}

	bool is_integer_overflow(string val) {
		bool is_negative = val[0] == '-' ? true : false;
		
		if (!is_negative) {
			// if val is positive, compare with INT_MAX
			string int_max = to_string(INT_MAX);
			val = val.substr(1);  // get the string without '+' sign

			if ((val.length() > int_max.length()) ||	// input length is longer => definitely overflow
				(val.length() == int_max.length() && (val > int_max))) {	// same length, but lexigraphically bigger => definitely overflow
				return true;
			}
		}
		else {
			// else compare with INT_MIN
			string int_min = to_string(INT_MIN).substr(1);	// get the string without '-' sign
			val = val.substr(1);  // get the string without '-' sign

			if ((val.length() > int_min.length()) ||	// input length is longer => definitely overflow
				(val.length() == int_min.length() && (val > int_min))) {		// same length, but lexigraphically bigger => definitely overflow
				return true;
			}
		}

		// this should never be reached, but is needed for LeetCode OJ otherwise may encounter 'control reaches non-void function' error
		return false;
	}

	bool is_numerical_char(char c) {
		return (c >= '0' && c <= '9') ? true : false;
	}
};

int main(void) {
	Solution* soln = new Solution();

	cout << soln->myAtoi("+1") << endl;

	return 0;
}