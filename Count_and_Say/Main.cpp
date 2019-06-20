#include <string>
#include <iostream>

using namespace std;

// Problem: Count and say

// «ä¸ô:
//

class Solution {
public:
	string countAndSay(int n) {

		if (n == 1)
			return "1";
		else
		{
			string prev = countAndSay(n - 1);
			string result = "";

			for (int i = 0; i < prev.length(); )
			{
				char c = prev[i];
				int count = 0;
				while (c == prev[i])
				{
					count++;
					i++;
				}
				result.append(std::to_string(count));
				result.append(1, c);
			}

			return result;
		}
	}
};

int main()
{
	Solution *soln = new Solution();
	string output = soln->countAndSay(10);
	cout << output << endl;
	return 0;
}