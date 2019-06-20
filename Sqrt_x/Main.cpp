#include <string>
#include <iostream>

// Problem: Sqrt(x)

// «ä¸ô: °Ñ¦Ò Grandyang

// ³´¨À:
// 1. The relation between 'left' and 'right' in the loop condition for binary search
// 2. overflow when using mid*mid if mid > sqrt(INT_MAX)

using namespace std;

class Solution {
public:
	int mySqrt(int x) {
		if (x <= 1)
			return x;
		
		int left = 1, right = x;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (mid < (x / mid))	// can't write it as: if((mid * mid) < x) because (mid * mid) overflows when (mid > sqrt(INT_MAX)). For example, a test case of '2147395599' will fail here
				left = mid + 1;
			else if (mid > (x / mid))	// same as above, cannot write as ((mid*mid) > x)
				right = mid - 1;
			else	// when the input is a perfect square, e.g. 9, 16, 25, ...100, ...etc then the 'else' statement captures the (mid*mid) == x case
				return mid;
		}

		return left - 1;	// when we get out of the while loop, the index 'left' will be the one element higher than the true answer, so need to decrement by 1 here
	}
};

//class Solution {
//public:
//	int mySqrt(int x) {
//		if (x <= 1) return x;
//		int left = 0, right = x;
//		while (left < right) {
//			int mid = left + (right - left) / 2;
//			if (x / mid >= mid) left = mid + 1;
//			else right = mid;
//		}
//		return right - 1;
//	}
//};

int main(int argc, char *argv[])
{
	Solution *soln = new Solution();

	cout << soln->mySqrt(2147395599);

	return 0;
}