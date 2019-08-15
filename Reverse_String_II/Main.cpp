// Problem: Reverse String II

// Algorithm 1 (My own solution):
// Using input string length and k to determine how many segments this string can be divided into.
// Each segment is length 2k. For each segment, reverse the first k chars. We can work out the begin/end
// index that should be used for each segment by using the batch number.
// As for the final remaining chars, if the number of chars < k, reverse all of them
// if the number of k <= remaining chars < 2k, reverse the first k and leave the rest as they are

#include <string>

using namespace std;

class Solution {
public:
	string reverseStr(string s, int k) {
		size_t len = s.length();
		size_t batches = len / (2 * k);
		size_t remaining = (len % (2 * k));

		unsigned int begin_idx = 0;
		unsigned int end_idx = 0;
		int i = 0;

		// for each complete batch
		for (i = 0; i < batches; i++) {
			// work out the index range within this batch that is to be reversed
			begin_idx = i * 2 * k;
			end_idx = (i * 2 * k) + (k - 1);

			// swap the chars within the index range
			reverseString(s, begin_idx, end_idx);
		}

		// reverse the remaining chars
		if (remaining < k) {
			// reverse all
			begin_idx = i * 2 * k;
			end_idx = len - 1;
			reverseString(s, begin_idx, end_idx);
		}
		else if (remaining < (2 * k) && remaining >= k) {
			// reverse first k and leave the rest
			begin_idx = i * 2 * k;
			end_idx = (i * 2 * k) + (k - 1);
			reverseString(s, begin_idx, end_idx);
		}

		return s;
	}

private:
	void reverseString(string& s, unsigned int begin_idx, unsigned int end_idx) {
		for (; begin_idx < end_idx; begin_idx++, end_idx--) {
			char tmp = s[begin_idx];
			s[begin_idx] = s[end_idx];
			s[end_idx] = tmp;
		}
	}
};
