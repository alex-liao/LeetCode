// Problem: Reverse Words In A String

// Algorithm:
// Method 1 (My own solution):
// 1. Reverse the entire input string once
// 2. Then reverse individual words in the reversed string

#include <string>
#include <iostream>

using namespace std;

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

int main(void) {
	string s = " ";

	return 0;
}