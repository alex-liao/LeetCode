#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Problem: Remove Element

// «ä¸ô:

class Solution {
private:

public:
	int removeElement(vector<int>& nums, int val) {
		int i = 0;
		vector<int>::iterator it = nums.begin();

		while ((it+i) != nums.end())
		{
			if (*(it + i) == val)
				nums.erase(it + i);
			else
				i++;
		}

		return nums.size();
	}
};

int main(int argc, char *argv[])
{
	Solution *soln = new Solution();
	vector<int> v = { 3,2,2,3 };
	
	// testing
	cout << "size: " << soln->removeElement(v, 3) << endl;
	cout << "contents: ";
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << (*it);
		if ((it + 1) != v.end())
			cout << ", ";
	}
	cout << endl;

	return 0;
}