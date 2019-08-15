// Problem: Reverse Only Letters

// Algorithm 1 (My own solution):
// Make a copy of the input string and call it the result string. Since the locations of non-letters don't change,
// and also the length between the input string and result string are consistent and equal,
// we can pick up letters from back of the input string and start from the beginning of the result string to find
// appropriate locations to insert the letter. Continue with this process when we reach the beginning of the input string

#include <string>
#include <cctype>

using namespace std;

class Solution {
public:
	string reverseOnlyLetters(string S) {
		string res = S;
		size_t len = S.length();

		unsigned int idx = 0;

		for (int tail = len - 1; tail >= 0; tail--) {
			if (isalpha(S[tail])) {
				// find appropriate location to insert letter
				while (!isalpha(res[idx])) {
					// skip all non letters
					idx++;
				}
				res[idx] = S[tail];
				idx++;
			}
		}

		return res;
	}
};