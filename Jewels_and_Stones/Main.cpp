#include <iostream>
#include <string>
#include <map>

using namespace std;

// uses map
class Solution1 {
public:
	int numJewelsInStones(string J, string S) {
		map<char, string> is_jewel;
		int jewel_count = 0;

		for (int i = 0; i < J.length(); i++)
		{
			is_jewel[J[i]] = "";
		}

		for (int i = 0; i <= S.length(); i++)
		{
			if (is_jewel.find(S[i]) != is_jewel.end())
			{
				jewel_count++;
			}
		}

		return jewel_count;
	}
};

// uses unordered set

#include <unordered_set>

class Solution2 {
public:
	int numJewelsInStones(string J, string S) {
		std::unordered_set<char> set;

		int jewel_count = 0;

		for (int i = 0; i < J.length(); i++)
		{
			set.insert(J[i]);
		}

		for (int i=0; i < S.length(); i++)
		{
			if (set.count(S[i]))
				jewel_count++;
		}

		return jewel_count;
	}
};

int main()
{
	Solution1 soln1;
	cout << soln1.numJewelsInStones("aA", "aAAbbbb") << endl;

	Solution2 soln2;
	cout << soln2.numJewelsInStones("aA", "aAAbbbb") << endl;

	return 0;
}