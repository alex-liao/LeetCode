// Problem: Pascal's Triangle

// 思路: 
// 用 iterate 的方法，先準備好 "第一層" 跟 "第二層" 的 trivial solution，然把他們 push_back() 到 final solution 的 vector 裡面
// 之後的每一層，先 push_back() 一個 '1'(數值) 到該層的 vector 裡面，接下來拿上一層的 vector 出來，以 index ([0],[1]), ([1],[2]), ([2],[3])...etc 的方式
// 把每個 pair 做 sum，然後把每個 pair 的 sum push_back() 到這層的 solution vector 裡面，結束後再 push_back() 一個 '1'(數值)，再把這層的 solution vector push_back()
// 到 final solution vector 裡面


#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		vector<vector<int>> output;
		int i = 0;
		while (i < numRows)
		{
			if (i == 0)
			{
				vector<int> layer;
				layer.push_back(1);
				output.push_back(layer);
			}
			else if (i == 1)
			{
				vector<int> layer(2, 1);
				output.push_back(layer);
			}
			else
			{
				vector<int> curr_layer;
				
				curr_layer.push_back(1);
				// fetch the previous layer
				vector<int> prev_layer = output[(i-1)];
				// calculate the sums of pairs of elements from the previous layer
				for(unsigned int idx1=0, idx2=1; idx2 < prev_layer.size(); idx1++, idx2++)
				{
					int val = prev_layer[idx1] + prev_layer[idx2];
					curr_layer.push_back(val);
				}
				curr_layer.push_back(1);
				
				// insert current layer to output
				output.push_back(curr_layer);
			}

			i++;
		}

		return output;
	}
};

void print_vector(vector<vector<int>> &data)
{
	for (vector<vector<int>>::iterator it1 = data.begin(); it1 != data.end(); it1++)
	{
		for (vector<int>::iterator it2 = it1->begin(); it2 != it1->end(); it2++)
		{
			cout << *it2 << ", ";
		}
		cout << endl;
	}
}

int main(int argc, char *argv[])
{
	int numRows = 5;

	Solution *soln = new Solution();

	vector<vector<int>> output = soln->generate(numRows);
	print_vector(output);
	return 0;
}