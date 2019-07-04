// Problem: Reverse Words In A String

// Algorithm:
// Method 1 (My own solution):
// 1. Reverse the entire input string once
// 2. Then reverse individual words in the reversed string

#include <string>
#include <iostream>

using namespace std;

// This solution uses way too much memory and is too slow
// Runtime: 20ms (faster than 25% of C++ submissions)
// Memory: 133.7 MB (less than 5% of C++ submissions)
class Solution {
public:
	string reverseWords(string s) {
		string res = "";

		if (!s.empty()) {
			// trim the leading and trailing space chars
			std::size_t idx1 = s.find_first_not_of(" ");

			// entire string contains only white space, just return empty string
			if (idx1 == string::npos) {
				return "";
			}

			std::size_t idx2 = s.find_last_not_of(" ");
			s = string(s, idx1, (idx2 - idx1 + 1));

			// first, do a complete reverse on the trimmed input string
			s = reverse(s);

			// for each word in the string, perform a reverse again and concat it to the output
			int j = 0, i = j;
			while (j < s.length()) {
				// find the space char between this word and next word
				if (s[j] != ' ' && j < s.length()) {
					j++;
					// only go to next iteration if we're not at last word
					if (j != s.length()) {
						continue;
					}
				}

				string tmp = string(s, i, (j-i));
				tmp = reverse(tmp);
				
				// if this is the first word, just append it
				if (res.empty()) {
					res += tmp;
				}
				else {	// else, append a single white space char then append the word
					res = res + " " + tmp;
				}

				// find the beginning of the next word
				while (s[j] == ' ') {
					j++;
				}
				i = j;	// both i and j now points to the first char of the next word
			}
		}

		return res;
	}

	string reverse(string s) {
		string res = "";
		for (int i = s.length() - 1; i >= 0; i--) {
			res += s[i];
		}

		return res;
	}
};

// Solution 2: Improve on previous solution
// * Without creating too many new string objects
// * Reverse the words by extracting chars in reverse order from reversed string
// Runtime: 8ms (90% faster than other C++ submissions)
// Mem: 10 MB (less than 65.8% of other C++ submissions)
class Solution2 {
public:
	string reverseWords(string s) {
		int len = s.length();
		string res = "";

		if (len) {
			// reverse the input string first
			reverse(s.begin(), s.end());

			int i = 0;
			bool first_word = true;
			while (i < len) {
				// skip any leading (or could be trailing) white-space chars
				while (s[i] == ' ') {
					i++;
					if (i == len) {
						break;
					}
				}

				// if i == len, either the string was all white-space chars, or we were skipping
				// trailing spaces before and now we've reached end of string
				if (i == len) {
					break;
				}

				// otherwise, i is pointing to the beginning of a word, make j point to that too
				int j = i;

				// keep skipping until we find the next white-space char (word delimiter) or reach end of string
				while (s[i] != ' ' && i != len) {
					i++;
				}

				// now i points to the delimiter, and make k point to end of a word
				int k = i - 1;
				
				// if we're not working on the first word, need to append a space char first
				if (!first_word) {
					res += ' ';
				}

				// reverse a word by extracting chars from the end of the word
				// and append to output string
				while (k >= j) {
					res += s[k];
					k--;
				}

				// after we've encountered the first word, the flag needs to be set to false
				if (first_word) {
					first_word = false;
				}
			}
		}

		return res;
	}
};
