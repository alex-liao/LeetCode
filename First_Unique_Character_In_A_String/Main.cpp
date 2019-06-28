// Problem: First Unique Character in A String

// Algorithm:
// Method 1 (My own solution):
// 1. Create a Set
// 2. Iterate through the string, starting from the first character
// 3. For each character:
//		Check if it already exists in the set:
//			if yes =>
//				skip to check next character
//			if no =>
//				add it to the set
//				check the rest of the string to see if it is unique
//					if unique =>
//						return its index
//					else =>
//						skip to check next character
// 4. Repeat the above process until we find the first unique char or we reach the end of the string

// Method 2 (My own solution):
// 1. Create a map
// 2. Calculate the occurrence count of each char and store the char:count mapping to the map
// 3. Iterate through the string to find the first char that has an occurrence count of 1 and return its index

#include <string>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
	int firstUniqChar(string s) {
		set<char> chars;

		for (int i = 0; i < s.length(); i++) {
			if (chars.find(s[i]) != chars.end()) {
				// already in set, move on to check next char
				continue;
			}
			else {
				chars.insert(s[i]);	// add to set
				bool uniq = true;
				// check for the rest of the string to see if char is unique
				for (int j = i + 1; j < s.length(); j++) {
					if (s[j] == s[i]) {
						// s[i] is not unique, set flag and break out
						uniq = false;
						break;
					}
				}

				// if the flag 'uniq' is still true, then s[i] is the first unique char in the string, return its index
				if (uniq) {
					return i;
				}
			}
		}

		return -1;
	}
};

class Solution2 {
public:
	int firstUniqChar(string s) {
		map<char, int> counts;
		int res = -1;

		// get occurrence counts
		for (int i = 0; i < s.length(); i++) {
			map<char, int>::iterator it = counts.find(s[i]);
			if (it != counts.end()) {
				it->second++;
			}
			else {
				counts.insert(pair<char, int>(s[i], 1));
			}
		}

		// now iterate the string to find the first element with occurrence count of 1
		for (int i = 0; i < s.length(); i++) {
			int count = counts.find(s[i])->second;
			if (count == 1) {
				res = i;
				break;
			}
		}

		return res;
	}
};