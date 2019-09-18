// Problem: Find Common Characters

// Algorithm 1 (my own solution):
// 1. Create a map to map letters a-z to vectors of length A.length()
//    e.g. m['a'] = [0....n], m['b'] = [0....n]	...etc
// 2. For each letter a-z, go through the list of strings (A[0] ~ A[n]) to find out
//    how many times the letter occurs in each string, update the count in the map
// 3. For eahc letter a-z, sort the occurrence frequency vector,
//    if the minimum is 0, this means a particular letter did not exist in one of the strings,
//	  then we can ignore this letter and do not add it to result
// 4. Otherwise, add the letter to the result vector the minimum occurence frequency number of times
//    because this is the lowest common occurrence count for the letter across all strings

#include <algorithm>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Solution {
public:
	vector<string> commonChars(vector<string>& A) {
		map<char, vector<int>> m;
		vector<string> res;

		// init the map first
		// the map represents for each char a-z how many times it occurs in string A[0] to A[n]
		for (char c = 'a'; c <= 'z'; c++) {
			m[c] = vector<int>(A.size());
		}

		// populate the map
		for (int i = 0; i<A.size(); i++) {
			for (int j = 0; j<A[i].length(); j++) {
				char tmp = A[i][j];
				m[tmp][i]++;
			}
		}

		// for each char a-z, sort it's associated vector
		for (char c = 'a'; c <= 'z'; c++) {
			sort(begin(m[c]), end(m[c]));
			// if this letter doesn't exist in one of the strings, no need to add this char to result
			if (m[c][0] == 0) {
				continue;
			}
			// find the minimum common number of times this letter had occurred in all strings and 
			// add it to the result that number of times
			else {
				for (int i = 1; i <= m[c][0]; i++) {
					res.push_back(string(1, c));
				}
			}
		}

		return res;
	}
};