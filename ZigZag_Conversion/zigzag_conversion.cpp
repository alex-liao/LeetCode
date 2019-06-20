#include <iostream>
#include <string>

// Problem: ZigZag Conversion

// Status: Unfinished, Debugging

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        string result = "";

        int line = 1;
        int str_len = s.length();
        while(line <= numRows) {
            int index = 0;
            int direction = 1;
            int on_row = 1;
            while(index < str_len) {
                if(on_row == 1 && direction == -1) {
                    direction = 1;
                }
                else if(on_row == numRows && direction == 1) {
                    direction = -1;
                }

                if(on_row == line) {
                    result += s[index];
                }
                on_row += direction;
                index++;
            }
            line++;
        }

        return result;
    }
};

int main() {
    Solution soln;
    cout << soln.convert("PAYPALISHIRING", 3) << endl;

    return 0;
}