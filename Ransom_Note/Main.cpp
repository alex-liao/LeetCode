// Problem: Ransom Note

// Thought Process:

// Method 1:
// 1. Use an array of size 26 to represent the 26 lower case alphabets.
// 2. Iterate through the magazine string and tally by INCREMENTING the occurrences of each char in the array
// 3. Iterate through the ransom string and tally by DECREMENTING the occurrences of each character in the array
// 4. While iterating through ransom string, if any occurrence becomes < 0, return false. Otherwise return true

// Method 2:
// Sort the two strings then check if ransom note is a substring of magazine string. If so, then return true, else return false

#include <string>
#include <iostream>
#include <utility>
#include <map>

using namespace std;

class Solution {
public:
	bool canConstruct(string ransomNote, string magazine) {
		int occurrences[26];

		// initialize the array to 0 in a backwards compatible (with C) fashion
		for (int i = 0; i < 26; i++) {
			occurrences[i] = 0;
		}

		for (int i = 0; i < magazine.length(); i++) {
			occurrences[(magazine[i] - 'a')]++;
		}

		for (int i = 0; i < ransomNote.length(); i++) {
			if ((--occurrences[(ransomNote[i] - 'a')]) < 0) {
				return false;
			}
		}

		return true;
	}
};

int main(void) {
	Solution* soln = new Solution();
	cout << soln->canConstruct("aa", "aab") << endl;
}