// Problem: Intersection of two arrays

// Algorithm:
// Method 1 (My own solution):
// 1. create a std::set
// 2. Iterate through one of the array and insert all its elements into the set
// 3. Iterate through the other array, checking for elements that are common to both arrays using the set
// 4. For common elements, push them into the result vector
// 5. Remove the common element from the set, otherwise if we again encounter a common element that we've came across before, we would insert duplicate values into the result vector

#include <vector>
#include <set>

using namespace std;

class Solution {
public:
	vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
		vector<int> res;
		set<int> nums1_elems;

		// insert nums1 elems into set
		for (vector<int>::iterator it = nums1.begin(); it != nums1.end(); it++) {
			if (nums1_elems.find(*it) == nums1_elems.end()) {
				nums1_elems.insert(*it);
			}
		}

		// check nums2 for common elements
		for (vector<int>::iterator it = nums2.begin(); it != nums2.end(); it++) {
			if (nums1_elems.find(*it) != nums1_elems.end()) {
				// common element found, insert it into result vector
				res.push_back(*it);

				// remove the common element from the set, as we don't want duplicates in our result vector
				nums1_elems.erase(*it);
			}
		}

		return res;
	}
};