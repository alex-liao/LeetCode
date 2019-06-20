// Problem: Ugly number

// «ä¸ô:
// Method 1 (Works, but time limit exceed when judged by LeetCode OJ):
// try finding factors, starting from 2, only need to check up to <= (num / 2)
// if a factor is found, check if it is valid (2, 3 or 5)
// if it is valid, continue with the recursion using (num / factor) as the new parameter, until either we reach invalid, or if (num / factor) = 1
// if it is invalid, return false directly.

// Method 2:
// 

#include <iostream>

using namespace std;

class Solution {
public:
	bool isUgly(int num) {
		
	}


	// ========================= Exceeds Time Limit solution =========================
		//bool isUgly(int num) {
		//	// negative numbers are not ugly numbers
		//	if (num <= 0)
		//		return false;
		//
		//	// 1 is typically treated as an ugly number, we'll define so for zero as well
		//	if (num == 1 || num == 0)
		//		return true;
		//
		//	return isUglyRecursiveCall(num);
		//}

		//bool isUglyRecursiveCall(int num) {
		//	// we've factorized down to 2,3,5 themselves
		//	if (num == 2 || num == 3 || num == 5)
		//		return true;

		//	// for inputs other than 2,3,5, check for its factors, starting from 2, up until (num / 2).
		//	for (int i = 2; i <= (num / 2); i++) {
		//		// found a factor
		//		if ((num % i) == 0) {
		//			// DEBUG: print out the factor
		//			cout << i << endl;

		//			// base case, we have completely "prime factorized" the input
		//			if ((num / i) == 1)
		//				return true;
		//			// found one prime factor, continue with next recursive call
		//			if (i == 2 || i == 3 || i == 5) {
		//				return isUglyRecursiveCall((num / i));
		//			}
		//			else {
		//				return false;
		//			}
		//		}
		//	}

		//	return false;
		//}
};
