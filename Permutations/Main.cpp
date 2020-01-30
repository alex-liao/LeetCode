// Problem: Permutations

// Algorithm 1 (my own solution):
// This problem is a DFS/Backtracking problem by nature and can be solved by
// using a combination of 'loop' and 'recursion'.
// The idea is as follows:
// 1. Iterate over the input vector, with each element being interated representing
//    the element that we pick to be part of the resulting permutation.
//    E.g. Suppose the input given was {1,2,3}, and if we pick 1 to be the our first element, then:
//    the permutation we're building is: {1}
//    what we can still choose from is: {2, 3}
// 2. In each iteration, after we've picked the element that we want, we need to perform the picking process
//    from the remaining vector ({2, 3}) using recursion.
//    E.g. Suppose we pick 2 from {2,3}, then we'd have:
//    permutation we're building: {1,2}
//    what's left to pick from: {3}
//    Suppose we continue the recursive picking process again (by picking 3 from {3}), we'd have:
//    permutation we're building: {1,2,3}
//    what's left to pick from: {}
//    This shows the base case for the recursion, which is "if the input vector becomes empty, then we'd have
//    obtained a valid permutation" and we need to push this valid permutation into the output vector<vector<int>>
// 3. Now we need to unwind the recursion stack to the scenario where
//    the permutation we're building is: {1}
//    what we can still choose from is: {2, 3}
//    but we're going to choose 3 instead of choosing 2 from {2,3}
//    Notice that the loop occurrs within the recursion, and that every time before we iterate to the next item 
//    (regardless of which level of recursion we're currently at), we need to remove the last item from the permutation
//    that we're building and restore that item back into the input vector (to be used in the next recursive calls)
//    In our example, we need to remove 2 from {1,2} (permutation we're building)
//    and add it back to {3} (remaining items to select from), resulting in:
//    {1} and {2,3}
//    before we can iterate to pick 3 from {2,3}
// 4. The same entire process applies when we unwind the recursive stack to the top level and we pick 2 instead of 1 from {1,2,3}
//    then we'd get:
//    1. {2} and {1,3}
//    2. {2,1} and {3}
//    3. {2,1,3} and {}
//    then:
//    1. {2} and {1,3}	Notice how "{2} and {1,3}" results from 1 being removed from {2,1} and added to {3} resulting in {1,3}
//    2. {2,3} and {1}
//    3. {2,3,1} and {}
// 5. Repeat the process above for all levels of recursion, and in the end we'd get all possible permutations

#include <string>
#include <iostream>
#include <vector>

using namespace std;

// Solution 1
class Solution1 {
private:
	void permuteRecursion(vector<vector<int>>& res, vector<int> input, vector<int>& permutation) {
		if (input.empty()) {
			res.push_back(permutation);
			return;
		}

		for (vector<int>::iterator it = input.begin(); it != input.end(); it++) {
			// pick the element pointed to by the iterator and add it to our permutation that's being built
			permutation.push_back(*it);
			vector<int> tmp = input;
			// a copy of the input vector without the element we just picked will be used as input vector for next recursion
			// This basically means "solve the sub-problem (which is a smaller input array)"
			tmp.erase(std::find(tmp.begin(), tmp.end(), *it));
			// call recursion with the tmp vector (which is a reduced input vector as it is without the element we just picked)
			permuteRecursion(res, tmp, permutation);
			// remove the item we just picked from our permutation being built
			permutation.pop_back();
		}
	}

public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> permutation;
		permuteRecursion(res, nums, permutation);
		return res;
	}
};

// Solution 2
// This is an optimization to Solution 1. Instead of copying the entire input array then remove an element from it,
// we simply preserve the element in a variable and remove it from the input array. The input array is then used for
// the next recursion call and after the stack unwinds back, we insert the value back to its original place in the
// vector
class Solution {
private:
	void permuteRecursion(vector<vector<int>>& res, vector<int>& input, vector<int>& permutation) {
		if (input.empty()) {
			res.push_back(permutation);
			return;
		}

		for (vector<int>::iterator it = input.begin(); it != input.end(); it++) {
			// pick the element pointed to by the iterator and add it to our permutation that's being built
			int val = *it;
			permutation.push_back(val);

			// remove the picked element from input array before passing the input array to next level of recursion
			input.erase(it);

			// call recursion with the tmp vector (which is a reduced input vector as it is without the element we just picked)
			permuteRecursion(res, input, permutation);

			// re-insert the removed element back to its original position after the recursion stack unwinds back
			input.insert(it, val);

			// remove the item we just picked from our permutation being built
			permutation.pop_back();
		}
	}

public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> res;
		vector<int> permutation;
		permuteRecursion(res, nums, permutation);
		return res;
	}
};

// override cout's << operator to print a vector<vector<int>>
ostream& operator<<(ostream& os, vector<vector<int>>& v)
{
	cout << v.size() << endl;
	cout << "[" << endl;
	for (auto i = v.begin(); i != v.end(); i++) {
		cout << "    [";
		for (auto j = (*i).begin(); j != (*i).end(); j++) {
			if ((j + 1) != (*i).end()) {
				cout << (*j) << ",";
			}
			else {
				cout << (*j);
			}
		}
		if ((i + 1) != v.end()) {
			cout << "]," << endl;
		}
		else {
			cout << "]" << endl;
		}
	}
	cout << "]" << endl;

	return os;
}

int main(int argc, char *argv[])
{
	vector<int> input = { 1,2,3 };
	vector<vector<int>> res = Solution().permute(input);

	cout << res << endl;

	return 0;
}