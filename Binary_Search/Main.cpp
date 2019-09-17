// Problem: Binary Search

// Algorithm 1 (my own solution):
// This is just ordinary BST algorithm.
// 1. Define upper and lower bounds of the search as the two ends of the input array, 
//    then choose the middle element as the pivot for comparison.
// 2. If the pivot equals the target element, return the pivot's index.
// 3. If the target is greater than pivot, then it must be in the right half of the array, 
//    reset the upper/lower search bounds to become: (pivot+1) and (upper unchanged).
// 4. If the target is smaller than pivot, then it must be in the left half of the array,
//    reset the upper/lower search bounds to become: (lower unchanged) and (pivot-1).

#include <vector>

using namespace std;

class Solution {
public:
	int search(vector<int>& nums, int target) {
		int lower = 0, upper = nums.size() - 1;
		while (lower <= upper) {
			// pivot is the index of the element in the array 'nums' that we had chosen for comparison
			// typically it is the element at the middle of the array
			unsigned int pivot = (lower + upper) / 2;
			if (nums[pivot] == target) {
				return pivot;
			}
			else if (target > nums[pivot]) {
				lower = pivot + 1;
			}
			else {
				upper = pivot - 1;
			}
		}
		// not found
		return -1;
	}
};