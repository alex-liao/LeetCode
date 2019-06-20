#include <string>
#include <iostream>
#include <vector>

#include "BinaryTreeHelper.h"

using namespace std;

int main(int argc, char *argv[])
{
	BinaryTreeHelper* bt_helper = new BinaryTreeHelper();

	vector<string> input = {"1"};

	TreeNode* root = bt_helper->buildTree(input);

	return 0;
}