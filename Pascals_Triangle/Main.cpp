// Problem: Pascal's Triangle

// ���: 
// �� iterate ����k�A���ǳƦn "�Ĥ@�h" �� "�ĤG�h" �� trivial solution�A�M��L�� push_back() �� final solution �� vector �̭�
// ���᪺�C�@�h�A�� push_back() �@�� '1'(�ƭ�) ��Ӽh�� vector �̭��A���U�Ӯ��W�@�h�� vector �X�ӡA�H index ([0],[1]), ([1],[2]), ([2],[3])...etc ���覡
// ��C�� pair �� sum�A�M���C�� pair �� sum push_back() ��o�h�� solution vector �̭��A������A push_back() �@�� '1'(�ƭ�)�A�A��o�h�� solution vector push_back()
// �� final solution vector �̭�


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