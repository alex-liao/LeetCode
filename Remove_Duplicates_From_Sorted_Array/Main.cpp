#include <iostream>
#include <vector>

using namespace std;

// Problem: Remove Duplicates From Sorted Array

// ��� (Alex):
// 1. ������ vector::begin() ���o vector ���_�l (head)�A�åB�t�W�@�� offset counter (��l�Ƭ� 0)
//    �o�˫K�i�H�ϥ� head + offset �ӼаO vector ���� element�C
// 2. �H head+offset ��@�ثe�� element, head+offset+1 ���U�@�� element
// 3. ���U�Ӧ���ر��p:
//    1. �p�G�ثe�� element �P�U�@�� element �� duplicate, �h�� vector::erase() �����ثe�� element, �åB���ݭn increment offset counter,
//       �]����� erase() ���� element �ɡAvector �|�ۦ��C�� element ���e shift �@��
//    2. �p�G���O duplicate, �h�� offset counter increment 1, �o�˪��ܡA�ΨӬݥثe element ���лx (head+offset) �N�|�h�ݤU�@�� element�A
//       �� (head+offset+1) �N�|�ܦ��h�аO "�U�U��" element
// 4. �p���`���A����аO�U�@�� element ������ (head+offset+1) �O���� vector �����I (vector::end())

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {

		std::vector<int>::iterator head = nums.begin();
		int i;

		// using (head + i) to mark the current item that we are looking at
		for (i = 0; (head + i) < nums.end();)
		{
			// if reaching the last item in vector, break
			if ((head + i + 1) == nums.end())
				break;

			// if the current item we're looking at is a duplicate (when comparing against the next item in line)
			// we erase it and there's no need to increment the index 'i'
			if (*(head + i) == *(head + i + 1))
				nums.erase(head + i);
			else
				// current item is not a duplicate, increment index 'i'
				i++;
		}

		return nums.size();
	}
};

int main(int argc, char *argv[])
{
	Solution *soln = new Solution();

	// Testing Code
	std::vector<int> v;
	int i;
	
	v = {};
	cout << "size: " << soln->removeDuplicates(v) << endl;
	cout << "contents: [";
	for (i = 0; i < v.size(); i++)
	{
		if (i != 0)
		{
			cout << " ";
		}
		cout << v[i];
	}
	cout << "]" << endl;

	v = { 1,2,2,3,3,3,4,5 };
	cout << "size: " << soln->removeDuplicates(v) << endl;
	cout << "contents: [";
	for (i = 0; i < v.size(); i++)
	{
		if (i != 0)
		{
			cout << " ";
		}
		cout << v[i];
	}
	cout << "]" << endl;

	return 0;
}