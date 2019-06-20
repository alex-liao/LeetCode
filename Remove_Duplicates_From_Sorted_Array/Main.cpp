#include <iostream>
#include <vector>

using namespace std;

// Problem: Remove Duplicates From Sorted Array

// 思路 (Alex):
// 1. 首先用 vector::begin() 取得 vector 的起始 (head)，並且配上一個 offset counter (初始化為 0)
//    這樣便可以使用 head + offset 來標記 vector 中的 element。
// 2. 以 head+offset 當作目前的 element, head+offset+1 為下一個 element
// 3. 接下來有兩種情況:
//    1. 如果目前的 element 與下一個 element 為 duplicate, 則用 vector::erase() 移除目前的 element, 並且不需要 increment offset counter,
//       因為當用 erase() 移除 element 時，vector 會自行把每個 element 往前 shift 一格
//    2. 如果不是 duplicate, 則把 offset counter increment 1, 這樣的話，用來看目前 element 的標誌 (head+offset) 就會去看下一個 element，
//       而 (head+offset+1) 就會變成去標記 "下下個" element
// 4. 如此循環，直到標記下一個 element 的指標 (head+offset+1) 是指到 vector 的終點 (vector::end())

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