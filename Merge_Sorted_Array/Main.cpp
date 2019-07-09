// Problem: Merge Sorted Array

// Algorithm:
// Method 1 (My own solution):
// Create a new result vector, iterate through nums1 and nums2, inserting elements
// into the result vector in order. When iteration ends for both nums1 and nums2,
// clear nums1 and insert elements from result vector to nums1.

// Method 2 (Refer to Grandyang):
// Working backwards from the end of :
// 1. the merged array (end of nums1)
// 2. the end of valid data in nums1
// 3. the end of nums2
// we can insert the elements from nums1 and nums2 in order into the back of nums1
// until we reach the 0th index in nums1 and nums2

#include <vector>
#include <iostream>

using namespace std;

// Solution 1
class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> sorted;

		vector<int>::iterator it_nums1 = nums1.begin();
		vector<int>::iterator it_nums2 = nums2.begin();

		// nums1's size should be m + n, and the valid data should be located within the index ranges: 0 ~ (m-1)
		// the first index for nums1 that represents pre-allocated space for merged array should be at index m
		// therefore, the iterator for real end of nums1 is (nums1.begin() + m)
		vector<int>::iterator it_nums1_end = it_nums1 + m;

		while (it_nums1 != it_nums1_end && it_nums2 != nums2.end()) {
			if (*it_nums1 <= *it_nums2) {
				sorted.push_back(*it_nums1);
				it_nums1++;
			}
			else {
				sorted.push_back(*it_nums2);
				it_nums2++;
			}
		}

		// now see which one (nums1 or nums2) still has elements remaining
		if (it_nums1 == it_nums1_end) {
			// nums2 still has elements...
			while (it_nums2 != nums2.end()) {
				sorted.push_back(*it_nums2);
				it_nums2++;
			}
		}
		else {
			// nums1 still has elements...
			while (it_nums1 != it_nums1_end) {
				sorted.push_back(*it_nums1);
				it_nums1++;
			}
		}

		// finally, clear nums1 and copy sorted vector to nums1
		nums1.clear();
		// copy the sorted vector to nums1
		nums1 = sorted;
	}
};

// Solution 2
class Solution2 {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		// find the end of valid datum in nums1 and nums2
		int i = m - 1;
		int j = n - 1;

		// find the end of the merged array
		int k = (m + n) - 1;

		while (j >= 0) {
			// if there are still elements in nums1 to be compared
			if (i >= 0) {
				if (nums1[i] > nums2[j]) {
					nums1[k] = nums1[i];
					i--;
				}
				else {
					nums1[k] = nums2[j];
					j--;
				}
				k--;
				continue;
			}

			// if there are still remaining elements in nums2, insert them
			if (j >= 0) {
				nums1[k] = nums2[j];
				j--;
				k--;
			}
		}

		// there's nothing to do after getting out of the while loop, because if there
		// are more elements left in nums1, they would be in the correct order and at
		// the correct indices
	}
};

int main(void) {
	Solution* soln = new Solution();

	soln->merge(vector<int>({1,2,3,0,0,0}), 3, vector<int>({2,5,6}),3);

	return 0;
}