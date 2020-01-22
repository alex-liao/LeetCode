// Problem: Unique Paths

// Algorithm 1(DFS):
// TBD
// Despite being correct, but DFS takes too long, and this problem is actually a 
// DP problem....which I didn't notice

// Solution 1: (DFS algorithm)
// TLE

class Solution {
public:
	// from problem statement, it looks like m is number of columns
	// and n is number of rows
	int uniquePaths(int m, int n) {
		int ans = 0;

		uniquePathsRecursive(m, n, 0, 0, ans);

		return ans;
	}

	void uniquePathsRecursive(int m, int n, int col, int row, int& count) {
		// we found the finish point
		if (col == (m-1) && row == (n-1)) {
			count++;
			return;
		}
		else {
			// at every square, we can either move down or right
			
			// first, we try to move right (if the move we will take is still within bounds)
			if (col < (m-1)) {
				uniquePathsRecursive(m, n, col+1, row, count);
			}

			// then, we try to move down (if the move we will take is still within bounds)
			if (row < (n-1)) {
				uniquePathsRecursive(m, n, col, row+1, count);
			}
		}
	}
};