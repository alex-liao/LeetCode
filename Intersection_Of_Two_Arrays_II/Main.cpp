// Problem: Intersection of Two Arrays II

// Algorithm 1 (my own solution):
// 1. Keep count of the occurrence frequencies of all elements in one array using a map
// 2. Iterate through all the elements in the other array, and check the element against
//    the occurrence frequency map. If the occurrence frequency for that element is > 0, then
//    push the element into the output array and drecrement the occurrence frequency by 1.
// 3. Continue the above process until we finish traversing the second array, and we will get
//    an array that represents the intersection of the two arrays

#include <unordered_map>

using namespace std;

class Solution {
public:
	vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
		unordered_map<int, int> map;
		vector<int> out;

		// insert elems of nums1 into the map
		for (auto n : nums1) {
			map[n]++;
		}

		for (auto n : nums2) {
			if (map[n] > 0) {
				out.push_back(n);
				map[n]--;
			}
		}

		return out;
	}
};