// Problem: To Lower Case

// Thought Process:
// Method 1 (My own solution):
// Iterate through the input string, for each character, if it is an upper case letter, add 32 to it (look at the ASCII table)

#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	string toLowerCase(string str) {
		for (int i = 0; i < str.length(); i++) {
			if (str[i] >= 'A' && str[i] <= 'Z') {
				str[i] += 32;
			}
		}
		return str;
	}
};

int main(void) {
	Solution* soln = new Solution();
	cout << soln->toLowerCase("Hello") << endl;
}