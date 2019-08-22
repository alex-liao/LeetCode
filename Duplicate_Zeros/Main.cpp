// Problem: Duplicate Zeros

// Algorithm 1 (my own solution):
// Naive method, in-place but using additional memory (a queue)
// 1. Insert the elements that should be in the resulting array into a queue
// 2. Clear the input array
// 3. Insert the elements from queue back into input array

// Algorithm 2 (my own solution):
// In-place, without using additional memory
// Gather the elements that will be in the final array and insert from the back of the array

#include <vector>
#include <queue>

using namespace std;

// Algorithm 1
class Solution {
public:
	void duplicateZeros(vector<int>& arr) {
		size_t size = arr.size();

		// array has only 1 elem, do nothing
		if (size == 1) {
			return;
		}

		queue<int> q;

		unsigned int i = 0;
		unsigned int tmp = 0;
		while (tmp < size) {
			unsigned int elem = arr[i];
			q.push(elem);
			if (elem == 0) {
				tmp += 2;
			}
			else {
				++tmp;
			}
			++i;
		}

		// clear the input array
		arr.clear();

		// insert into input array using elements from the queue
		tmp = size;	// tmp represents remaining capacity in arr, decreases as we insert
		while (!q.empty() && (tmp > 0)) {
			int elem = q.front();
			q.pop();

			if (elem == 0) {
				if (tmp == 1) {
					arr.push_back(elem);
					--tmp;
				}
				else {
					arr.push_back(elem);
					arr.push_back(elem);
					tmp -= 2;
				}
			}
			else {
				arr.push_back(elem);
				--tmp;
			}
		}
	}
};

// Algorithm 2
class Solution2 {
public:
	void duplicateZeros(vector<int>& arr) {
		size_t size = arr.size();

		// array has only 1 elem, do nothing
		if (size == 1) {
			return;
		}

		unsigned int count = 0;
		int i = 0;

		while (count < size) {
			if (arr[i] != 0) {
				count++;
			}
			else {
				count += 2;
			}
			i++;
		}

		i--;	// now the index points to the last element we should keep

		for (auto it = (end(arr) - 1); it >= begin(arr);) {
			if (arr[i] == 0) {
				if (count > size) {
					*it = arr[i];	// just need to fill 1 position, because it's at the end
					count--;
				}
				else {
					*it = arr[i];
					it--;
					*it = arr[i];
				}
			}
			else {
				*it = arr[i];
			}
			it--;
			i--;
		}
	}
};