// Problem: Find The Difference

// «ä¸ô:
// Method 1:
// Tally the char frequencies for both strings. The char that has different frequency is the odd one out

// Method 2:
// Sum up all the 'offsets' of each character in string 's' from the character '`' (96 in decimal in ASCII table)
// then sum up all the 'offsets' of each character in string 't'. Mod the sum of string 't' by string 's', then use that to
// find which character is the extra one.

#include <string>
#include <map>
#include <iostream>

using namespace std;

class Solution {
public:
	char findTheDifference1(string s, string t) {
		map<char, int> s_freq;
		map<char, int> t_freq;

		for (int i = 0; i < s.length(); i++) {
			if (s_freq.find(s[i]) != s_freq.end()) {
				s_freq[s[i]] += 1;
			}
			else {
				s_freq[s[i]] = 1;
			}
		}

		for (int i = 0; i < t.length(); i++) {
			if (t_freq.find(t[i]) != t_freq.end()) {
				t_freq[t[i]] += 1;
			}
			else {
				t_freq[t[i]] = 1;
			}
		}

		for (map<char, int>::iterator it = t_freq.begin(); it != t_freq.end(); it++) {
			char c = it->first;
			
			// if the character from string t was not found in string s,
			// then it is the character that we are looking for
			map<char, int>::iterator tmp = s_freq.find(c);
			if (tmp == s_freq.end()) {
				return c;
			}
			else {
				// the character is found in both strings but the frequencies don't match,
				// then it is the char that we are looking for
				if (tmp->second != it->second) {
					return c;
				}
			}
		}

		// this should never occur, but is required if submitting to LeetCode OJ, otherwise will encounter "control reaches end of non-void function" error
		return '\0';
	}

	char findTheDifference2(string s, string t) {
		// if string 's' is empty, then simply return the first char in string 't'
		if (s.empty())
			return t[0];

		char char_map[] = {'`', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

		int s_sum = 0, t_sum = 0;
		
		for (int i = 0; i < s.length(); i++) {
			s_sum += s[i] - char_map[0];
		}

		for (int i = 0; i < t.length(); i++) {
			t_sum += t[i] - char_map[0];
		}

		int index = t_sum % s_sum;

		// special case handling for s="a", t="aa"
		if (index == 0)
			return char_map[1];

		return char_map[index];
	}
};

int main(void) {
	Solution *soln = new Solution();
	cout << soln->findTheDifference2("abcd", "abcde") << endl;
}