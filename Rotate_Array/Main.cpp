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

int main(void) {
	Solution2* soln = new Solution2();
	vector<int> input = { 1,2,3,4,5,6,7 };
	soln->rotate(input, 3);
	
	return 0;
}