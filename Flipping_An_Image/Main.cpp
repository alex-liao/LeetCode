// Problem: Flipping An Image

// Algorithm 1 (my own solution):
// To flip the image, we reverse reach row, to invert the image, we change every 0 to 1 and every 1 to 0.
// We can simply perform the reverse and flip for each row in one go as we process each row.

#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> flipAndInvertImage(vector<vector<int>>& A) {
		int i;
		for (i = 0; i < A.size(); ++i) {
			int j, k;
			for (j = 0, k = A[i].size() - 1; j < k; j++, k--) {
				// do swap and invert in one go
				unsigned int tmp = A[i][k];
				A[i][k] = !A[i][j];
				A[i][j] = !tmp;
			}
			if (j == k) {
				// array length is odd, need to invert the middle element
				A[i][j] = !A[i][j];
			}
		}

		return A;
	}
};