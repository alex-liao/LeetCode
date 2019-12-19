// Problem: Rotate Array

// Thought Process:
// Method 1 (My own solution, Time limit exceeded):
// 1. Find how many elements there are in the vector
// 2. Insert as many new elements to the front of the vector as there are elements in the vector.
// 3. For each of the original elements, calculate the index they should be at after the rotation, then update the element at that index
// 4. Remove the original elements

// Method 2 (My own solution):
// 1. Copy the input to a new vector
// 2. For each element in the new vector, calculate the index which it should be at after the rotation
// 3. Update the element to its proper index in the input vector

// Method 3 (Ref: Grandyang, also refer to solution tab for this question):
// This method is called "Cyclic Replacements" on the Solution tab for this problem on LeetCode.

#include <vector>

using namespace std;

class Solution1 {
public:
    void rotate(vector<int>& nums, int k) {
        int original_size = nums.size();
		
		// insert place holder elements at the front of the vector
		for(int i = 1; i <= original_size; i++) {
			vector<int>::iterator it = nums.begin();
			nums.insert(it, INT_MIN);
		}
		
		// calculate the index the original elements should be at after the rotation is performed
		int expanded_size = nums.size();
		for(int i = original_size; i < expanded_size; i++) {
			int new_index = (i + k) % original_size;
			nums[new_index] = nums[i];
		}
		
		// delete the original elements
		nums.erase((nums.begin() + original_size), nums.end());
    }
};

class Solution2 {
public:
	void rotate(vector<int>& nums, int k) {
		vector<int> tmp = nums;
		int size = nums.size();
		
		for(int i = 0; i < tmp.size(); i++) {
			int new_index = (i + k) % size;
			nums[new_index] = tmp[i];
		}
	}
};

// Very smart solution, does the job in-place too. The method is called 'Cyclic Replacement'
class Solution3 {
public:
	void rotate(vector<int>& nums, int k) {
		if (nums.empty() || (k % nums.size() == 0)) {
			return;
		}

		// represents the starting element which we picked for the process of cyclic replacement
		// Note: There are cases where we rotate by k steps and we keep on skipping some elements
		// in the array. In this case, we will increment 'start' by 1 to go to the next element
		int start = 0;

		// represents the index where replacement is going to occur in this iteration
		int idx = 0;

		// the preserved element from previous iteration, going to be moved to position 'idx' in this iteration
		int pre = 0;

		// the element that we are going to preserve in this iteration, which will be rotated to position +k
		// in the next iteration
		int cur = nums[0];

		// represents how many iterations we are going to perform, as there are n elements in the array that
		// needs to be relocated to their correct positions, we need to perform n iterations
		int n = nums.size();

		for (int i = 0; i < n; i++) {
			pre = cur;
			idx = (idx + k) % n;
			cur = nums[idx];
			nums[idx] = pre;

			// if idx looped back to where we started but there still remain elements which we've not relocated,
			// then increment start and begin the relocation process from there again.
			if (idx == start) {
				start++;
				idx = start;
				cur = nums[idx];
			}
		}
	}
};

int main(void) {
	Solution2* soln = new Solution2();
	vector<int> input = { 1,2,3,4,5,6,7 };
	soln->rotate(input, 3);
	
	return 0;
}