// Problem: Pascal's Triangle II

// «ä¸ô:

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		// use this variable to store output
		vector<int> res;

		vector<vector<int>> layers;
		int i = 0;	// start from layer 0
		while (i <= rowIndex)
		{
			if (i == 0)
			{
				vector<int> layer;
				layer.push_back(1);
				res = layer;
				layers.push_back(layer);
			}
			else if (i == 1)
			{
				// push two 1s into the vector
				vector<int> layer(2, 1);
				res = layer;
				layers.push_back(layer);
			}
			else
			{
				vector<int> curr_layer;

				curr_layer.push_back(1);
				// fetch the previous layer
				vector<int> prev_layer = layers[(i - 1)];
				// calculate the sums of pairs of elements from the previous layer
				for (unsigned int idx1 = 0, idx2 = 1; idx2 < prev_layer.size(); idx1++, idx2++)
				{
					int val = prev_layer[idx1] + prev_layer[idx2];
					curr_layer.push_back(val);
				}
				curr_layer.push_back(1);

				res = curr_layer;

				// insert current layer to all layers
				layers.push_back(curr_layer);
			}
			
			i++;
		}

		return res;
	}
};

void print_vector(vector<int> &data)
{
	for (vector<int>::iterator it1 = data.begin(); it1 != data.end(); it1++)
	{
		cout << *it1 << ", ";
	}
	cout << endl;
}

int main(int argc, char *argv[])
{
	int row_index = 5;

	Solution *soln = new Solution();

	vector<int> output = soln->getRow(row_index);
	print_vector(output);
	return 0;
}