// Problem: Letter Combinations of a Phone Number

// Algorithm 1 (my own solution) iterative solution:
// 1. For this problem, we are going to work backwards from the end of the digit string input, e.g.
//    for an input of "234", I am going to get the letter mapping for digit 4, then digit 3, then digit 2...etc
// 2. For each digit that we are working on, we need to first get it's corresponding string of letters,
//    and for each letter, we need to append behind the letter all the string combinations formed in the previous iteration
// 3. Prepare a result vector that contains all combination strings resulting from previous iteration, and for each digit and each
//    of the digit's letters, we use a separate tmp vector to store the new combination strings formed by the digit's letter and previous
//    combination strings.
// 4. When we're done with the current digit's current letter, we first clear the result vector then set the tmp vector's contents
//    to the result vector, so that the result vector can be used as source of combination strings in the next iteration
// 5. Finally, return the result vector after we've processed:
//    - all the digits in the input string
//    - all the letters in the string that corresponds to the digit

// Algorithm 2 (my own solution) recursive solution:
// TBD

#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, string> m = {
	{ '2', "abc" },
	{ '3', "def" },
	{ '4', "ghi" },
	{ '5', "jkl" },
	{ '6', "mno" },
	{ '7', "pqrs" },
	{ '8', "tuv" },
	{ '9', "wxyz" }
};

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		vector<string> res;

		for (int i = (digits.length() - 1); i >= 0; i--) {
			char digit = digits[i];
			string letters = m[digit];

			vector<string> tmp;

			for (char letter : letters) {
				// if this is the first digit that we're processing (remember that we are working backwards, from end to front)
				// then push all the letters the digit can represent into the vector
				if (i == (digits.length() - 1)) {
					tmp.push_back(string(1, letter));
				}
				else {
					// otherwise, need to append each letter to each string (excluding new strings from this digit)
					for (auto it = begin(res); it != end(res); it++) {
						tmp.push_back(string(1, letter) + *it);
					}
				}
			}

			res.clear();
			res = tmp;
		}

		return res;
	}
};
