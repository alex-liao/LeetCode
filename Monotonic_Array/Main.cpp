// Problem: Monotonic Array

// Algorithm 1 (my own solution):
// 1. If array length is 1, it is monotonic
// 2. Find the first occurrence where A[i] != A[i+1], starting from i=0
//	  If there's no such occurrence, then all elements in the array are equal, hence is monotonic
// 3. Otherwise, compare A[i] with A[i+1] to check if the array should be increasing or decreasing
// 4. Check the rest of the array and see if remaining elements follows the order found in step 3,
//    if any pair of elements do now follow the assumed order, then return false, else return true
//    at the end of this process.

#include <vector>

using namespace std;

class Solution {
public:
	bool isMonotonic(vector<int>& A) {
		// array of length 1, must be monotonic
		if (A.size() == 1) {
			return true;
		}

		// flag to represent increasing or decreasing
		bool inc = false;

		// find the first pair of elements A[i] and A[i+1] so that they do not equal
		int i = 0;
		for (; i < (A.size() - 1); i++) {
			if (A[i] != A[i + 1]) {
				break;
			}
		}

		// if all elemnts are the same value in the array, return true
		if (i == A.size() - 1) {
			return true;
		}
		else {
			// time to determine if array is increasing or decreasing
			if (A[i] < A[i + 1]) {
				inc = true;
			}
		}

		// check the array for monotonic-ness again from where we left off
		for (i = i + 1; i < (A.size() - 1); i++) {
			if (inc) {
				if (A[i + 1] < A[i]) {
					return false;
				}
			}
			else {
				if (A[i + 1] > A[i]) {
					return false;
				}
			}
		}

		return true;
	}
};