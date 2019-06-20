#include <iostream>
#include <string>
#include <cmath>

using namespace std;

const int MAX = (2 << 30) - 1;
const int MIN = (2 << 30);

class Solution {
public:
    int reverse(int x) {
		int output = 0;
		bool is_negative = false;

		// if input is 0, return 0
		if (!x)
			return 0;

		// test if we were given a negative input first
		if (x < 0)
		{
			is_negative = true;
			// convert input to positive first
			x = -x;
		}

        // if input's ending digit is 0, discard the ending digit by dividing the input by 10 until we've removed all trailing zeroes
		// only do this for one round and only on the raw input
        while(x % 10 == 0) {
            x /= 10;
        }

		// try to find out how many digits are there
		int y = x;
		int count = 0;
		while ((y / 10))
		{
			count++;
			y /= 10;
		}
		count++;	// don't forget to count in the final digit

		while (count)
		{
			output += (x % 10) * pow(10, (count-1));
			
			// overflow occurred, return 0
			if (output == MIN || output == MAX)
				return 0;

			x /= 10;
			count--;
		}

		if (is_negative)
		{
			output = -output;
		}

        return output;
    }
};

int main() {
	Solution *soln = new Solution();
	cout << soln->reverse(100) << endl;
	cout << soln->reverse(1534236469) << endl;

    return 0;
}