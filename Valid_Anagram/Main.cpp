// Problem: Valid Anagram

// Algorithm (My own solution):
// note: performance not very good, possible improvements?
// 1. Use a map for recording the occurrences of each char in string 's'
// 2. Iterate through each char in string 't', if the char does not
//	  exist in the map, then it is not an anagram of s, return false directly.
//	  Otherwise, decrement the counter for that character
// 3. Finally, iterate through the map to check if counters for all characters
//	  are reduced to 0. If true, then that means string 't' is anagram of string 's'
//	  otherwise return false

#include <string>
#include <map>

using namespace std;

class Solution {
public:
	bool isAnagram(string s, string t) {
		map<char, int> occurrences;

		for (char c : s) {
			if (occurrences.find(c) == occurrences.end()) {
				// first time we come across this character, init count to 1
				occurrences[c] = 1;
			}
			else {
				occurrences[c]++;
			}
		}

		for (char c : t) {
			if (occurrences.find(c) == occurrences.end()) {
				return false;
			}
			else {
				occurrences[c]--;
			}
		}

		for (auto it = occurrences.begin(); it != occurrences.end(); it++) {
			if ((it->second) != 0) {
				return false;
			}
		}

		return true;
	}
};