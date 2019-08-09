#include <iostream>
#include <string>
#include <vector>

// Problem: ZigZag Conversion

// Algorithm (My own solution): TBD

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
		string result = "";

		// special case handling for when transformation only has 1 row, just return the original string
		if (numRows == 1) {
			return s;
		}

		// initialize vector of strings to contain empty strings
		vector<string> lines;	// each index represents the corresponding line after zigzag transformation
		for (int i = 0; i < numRows; i++) {
			lines.push_back("");
		}

        int str_len = s.length();
		int idx = 0;
        int direction = 1;	// down is representd by 1, up is represented by -1. We start by going downwards
        int on_row = 0;	// represents which row we're currently on (from 0 to numRows-1)
        while(idx < str_len) {
			lines[on_row] += s[idx];

			// we are back to the first row from rows below, change direction to go down again
			if(on_row == 0 && direction == -1) {
                direction = 1;
            }
			// we reached the bottom row from higher rows up and direction is still going down, change direction to go up
            else if(on_row == (numRows - 1) && direction == 1) {
                direction = -1;
            }
            on_row += direction;
			idx++;
        }

		// glue all the lines after zigzag transformation to form the result string
		for (int i = 0; i < numRows; i++) {
			result += lines[i];
		}

        return result;
    }
};

int main() {
    Solution* soln = new Solution();
    cout << soln->convert("PAYPALISHIRING", 2) << endl;

    return 0;
}