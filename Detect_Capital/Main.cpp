// Problem: Detect Capital

// Algorithm 1 (My own solution):
// Split into 3 scenarios after having looked at the first and the second char.
// If the first char is lower case, the following letters can only be all lower case.
// If the first char is upper case, the following lettters either has to be
// all upper cases, or all lower cases. All other scenarios return false.

#include <cctype>
#include <string>

using namespace std;

class Solution {
public:
	bool detectCapitalUse(string word) {
		bool hasLowerCase = false;

		// case 2
		if (islower(word[0])) {
			for (int i = 1; i < word.length(); i++) {
				if (isupper(word[i])) {
					return false;
				}
			}
		}
		else {
			bool hasBeenLower = islower(word[1]) ? true : false;

			for (int i = 2; i < word.length(); i++) {
				if (hasBeenLower && isupper(word[i])) {
					return false;
				}
				else if (!hasBeenLower && islower(word[i])) {
					return false;
				}
			}
		}

		return true;
	}
};