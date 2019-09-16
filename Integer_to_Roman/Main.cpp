#include <string>
#include <iostream>
#include <stack>
#include <unordered_map>

// Problem: Integer to Roman
// input is guaranteed to be from 1 ~ 3999

// Algorithm 1 (my own solution):
// Get each digit by repetitive mod/div, starting from the LSB of the input
// keeping track of whether we're working on the 1s, 10s, 100s, or 1000s column
// and push the equivalent Roman Numeral string into a stack. When this process
// finishes, compose the result string by popping the Roman Numeral strings off
// of the stack and return it.

using namespace std;

class Solution {
public:
	string intToRoman(int num) {
		string res = "";
		stack<string> s;

		// use repeated div/mod, starting from input's LSB
		unsigned int power = 0;
		while (num > 0) {
			int residual = num % 10;
			string tmp = "";

			if (power == 0) {
				// handlings for 1s
				if (residual == 1) {
					tmp = "I";
				}
				else if (residual == 2) {
					tmp = "II";
				}
				else if (residual == 3) {
					tmp = "III";
				}
				else if (residual == 4) {
					tmp = "IV";
				}
				else if (residual == 5) {
					tmp = "V";
				}
				else if (residual == 6) {
					tmp = "VI";
				}
				else if (residual == 7) {
					tmp = "VII";
				}
				else if (residual == 8) {
					tmp = "VIII";
				}
				else if (residual == 9) {
					tmp = "IX";
				}
			}
			else if (power == 1) {
				// handlings for 10s
				if (residual == 1) {
					tmp = "X";
				}
				else if (residual == 2) {
					tmp = "XX";
				}
				else if (residual == 3) {
					tmp = "XXX";
				}
				else if (residual == 4) {
					tmp = "XL";
				}
				else if (residual == 5) {
					tmp = "L";
				}
				else if (residual == 6) {
					tmp = "LX";
				}
				else if (residual == 7) {
					tmp = "LXX";
				}
				else if (residual == 8) {
					tmp = "LXXX";
				}
				else if (residual == 9) {
					tmp = "XC";
				}
			}
			else if (power == 2) {
				// handlings for 100s
				if (residual == 1) {
					tmp = "C";
				}
				else if (residual == 2) {
					tmp = "CC";
				}
				else if (residual == 3) {
					tmp = "CCC";
				}
				else if (residual == 4) {
					tmp = "CD";
				}
				else if (residual == 5) {
					tmp = "D";
				}
				else if (residual == 6) {
					tmp = "DC";
				}
				else if (residual == 7) {
					tmp = "DCC";
				}
				else if (residual == 8) {
					tmp = "DCCC";
				}
				else if (residual == 9) {
					tmp = "CM";
				}
			}
			else if (power == 3) {
				// handlings for 1000s
				if (residual == 1) {
					tmp = "M";
				}
				else if (residual == 2) {
					tmp = "MM";
				}
				else if (residual == 3) {
					tmp = "MMM";
				}
			}
			
			s.push(tmp);

			++power;
			num /= 10;
		}

		// compose the result string from stack s
		while (!s.empty()) {
			res += s.top();
			s.pop();
		}

		return res;
	}
};
