// Problem: Robot Return To Origin

// Thought Process:
// Method 1 (My Solution):
// Iterate over the input string, compute the occurrence of each move. At the end, check that #Up == #Down and #Left == #Right

#include <string>

using namespace std;

class Solution {
public:
	bool judgeCircle(string moves) {
		int u = 0;
		int r = 0;

		for (int i = 0; i < moves.length(); i++) {
			if (moves[i] == 'U') {
				u++;
			}
			else if (moves[i] == 'D') {
				u--;
			}
			else if (moves[i] == 'R') {
				r++;
			}
			else if (moves[i] == 'L') {
				r--;
			}
		}

		return (u == 0) && (r == 0);
	}
};