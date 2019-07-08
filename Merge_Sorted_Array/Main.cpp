// Problem: Merge Sorted Array

// Algorithm:
// Method 1 (My own solution):
// Create a new result vector, iterate through nums1 and nums2, inserting elements
// into the result vector in order. When iteration ends for both nums1 and nums2,
// clear nums1 and insert elements from result vector to nums1.

// Method 2 (Refer to Grandyang):
//

#include <vector>
#include <iostream>

using namespace std;

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

int main(void) {
	Solution* soln = new Solution();

	soln->merge(vector<int>({1,2,3,0,0,0}), 3, vector<int>({2,5,6}),3);

	return 0;
}