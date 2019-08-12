// problem: Counting Bits

// Algorithm (My own solution):
// Convert each of the numbers between 0 ~ num to C++ std lib bitset
// and use the member function count() to count the number of 1s for
// each number. Push each of the result into output vector

#include <vector>
#include <bitset>

using namespace std;

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