// problem: Counting Bits
// Follow up:
// 1. Easy to do with O(n*sizeof(integer)), can you do it in single pass O(n)?
// 2. Space complexity should be O(n)
// 3. Can you do it without using C++ built in functions?

// Algorithm 1 (My own solution, using C++ built-in bitset):
// Convert each of the numbers between 0 ~ num to C++ std lib bitset
// and use the member function count() to count the number of 1s for
// each number. Push each of the result into output vector

// Algorithm 2: (My own solution, trivial solution):
// Dumb method, count each 1 bit as we go through each number from 0 ~ num.

#include <vector>
#include <bitset>
#include <iostream>

using namespace std;

class Solution {
public:
	vector<int> countBits(int num) {
		vector<int> res;

		for (int i = 0; i <= num; i++) {
			bitset<32> bs(i);
			res.push_back(bs.count());
		}

		return res;
	}
};

class Solution2 {
public:
	vector<int> countBits(int num) {
		vector<int> res;
		res.push_back(0);

		// use mod/div method to find the number of 1 bits in each number, bit by bit
		for (int i = 1; i <= num; i++) {
			unsigned int count = 0;
			int tmp = i;
			while (tmp > 0) {
				if (tmp % 2 != 0) {
					count++;
				}
				tmp /= 2;
			}
			res.push_back(count);
		}

		return res;
	}
};

int main(void) {
	vector<int> res = Solution2().countBits(5);
	
	for (auto it = begin(res); it != end(res); it++) {
		cout << *it << ' ';
	}
	cout << endl;

	return 0;
}