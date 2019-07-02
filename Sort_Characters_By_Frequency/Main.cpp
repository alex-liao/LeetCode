// Problem: Sort Characters By Frequency

// Algorithm:
// Method 1 (My own solution):
// 1. Traverse the string to find the occurrence counts for each character. Use a map data structure for mapping
// 2. Sort the occurrence counts using a sorting algorithm
// 3. Reconstruct a string object using the sorted characters

// Method 2:
// 1. Create a unordered map and store the character and its occurrence frequency mapping
// 2. Create a std::priority_queue and insert the pairs of char::occurrence frequency pairs into the priority queue
// 3. Reconstruct a string object by taking elements out of the priority queue in a descending order fashion.

// Method 3 (Ref: Grandyang):
// 1. Create an infinite array (such as a vector) of strings
// 2. Calculate the occurrence frequencies of each char and store the char and counts in a map
// 3. Iterate through the map, and append each char to the end of the string at array index which equals to the char's occurrence count
// 4. Iterate through the array backwards, and construct the result string

#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
#include <queue>

using namespace std;

// comparator function for sorting pairs based on the 2nd element's value in descending order
bool comparator(pair<char, int> &a, pair<char, int> &b) {
	return a.second > b.second;
}

class Solution {
public:
	string frequencySort(string s) {
		unordered_map<char, int> counts;
		vector<pair<char, int>> sorted;

		// calculate the occurrence counts
		for (int i = 0; i < s.length(); i++) {
			if (counts.find(s[i]) != counts.end()) {
				counts[s[i]]++;
			}
			else {
				counts[s[i]] = 1;
			}
		}

		// insert pairs into vector to be sorted
		for (unordered_map<char, int>::iterator it = counts.begin(); it != counts.end(); it++) {
			sorted.push_back(*it);
		}

		// sort the vector by occurrence frequency in descending order
		sort(sorted.begin(), sorted.end(), comparator);

		// construct string object for return
		string res = "";
		for (vector<pair<char, int>>::iterator it = sorted.begin(); it != sorted.end(); it++) {
			for (int i = 1; i <= it->second; i++) {
				res += it->first;
			}
		}

		return res;
	}
};

class Solution2 {
public:
	string frequencySort(string s) {
		unordered_map<char, int> counts;
		std::priority_queue<pair<int, char>> pq;

		// calculate the occurrence counts
		for (int i = 0; i < s.length(); i++) {
			if (counts.find(s[i]) != counts.end()) {
				counts[s[i]]++;
			}
			else {
				counts[s[i]] = 1;
			}
		}

		// insert <occurrence_freq, char> pairs into the priority queue
		for (unordered_map<char, int>::iterator it = counts.begin(); it != counts.end(); it++) {
			pq.push({ it->second, it->first });
		}

		string res = "";
		while (!pq.empty()) {
			pair<int, char> p = pq.top();
			pq.pop();
			res.append(p.first, p.second);
		}

		return res;
	}
};

class Solution3 {
public:
	string frequencySort(string s) {
		unordered_map<char, int> counts;
		vector<string> v(s.size() + 1);	// important to initialilze vector's size here

		// calculate the occurrence counts
		for (int i = 0; i < s.length(); i++) {
			if (counts.find(s[i]) != counts.end()) {
				counts[s[i]]++;
			}
			else {
				counts[s[i]] = 1;
			}
		}

		// insert the string formed by the char and it's occurrence count into the vector at the index represented by
		// the char's occurrence count
		for (unordered_map<char, int>::iterator it = counts.begin(); it != counts.end(); it++) {
			v[it->second].append(it->second, it->first);
		}

		// iterate the vector from the back and construct the result string
		string res = "";
		for (int i = v.size() - 1; i > 0; i--) {
			if (!v[i].empty()) {
				res.append(v[i]);
			}
		}

		return res;
	}
};
