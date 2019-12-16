// Problem: Remove Element

// Algorithm 1 (My own solution):
// Traverse the entire vector using the iterator (always pointing to the first elem)
// and an offset. When the value pointed to by (iter + offset) equals the val that we
// are looking for, call the built-in function erase() to remove that element from the
// vector. Otherwise, skip the element and increment the offset by 1. Do the process until
// we have completely traversed the entire vector, then return the final length of the
// vector

// Algorithm 2 (My own solution):
// Similar to solution 1, but without using the offset variable. Only use the iterator
// itself to traverse the vector. The rest is the same as Solution 1.

// Algorithm 3 (Ref: Grandyang):
// 非常精妙的 "快慢雙指針" 解法
// 基本概念是:
// 1. 用一個變數 (res) 做兩件事情:
//		# 紀錄在 vector 中，目前可以"被覆蓋掉值"的位置 (也就是說，這個 res 所指的位置的值，我們已經確定不要了)
//		# 同時也記錄了最後要輸出的"移除掉要找出的元素"之後的 vector 的長度 (因為在他之前的元素，我們都已經確定要保留)
//
//		這個變數所代表的意義，除了上面說的兩種功能之外，也標示著在該位置之前的元素，都是已經確定要保留的元素 (同上第2點)
//		注意，res 可以單純的 increment by 1, 因為res後面的值，如果有需要被保留的，都已經被複製到前面的位置去了，所以我們不用
//		擔心 res++ 會導致某些要保留的值會被蓋掉。
// 2. 用另一個變數 i 當作 index 去一個一個的 traverse vector 中的元素
// 3. 當 nums[i] 中的值，不是我們想要排除的值的時候，我們要保留 nums[i]，因此把 nums[i] 的值覆蓋到 nums[res] 去，因為 res
//    標示了目前可以被覆蓋的位置。
// 4. 當 nums[i] 中的值等於我們要排除的值的時候，反而甚麼都不用做，只需要把 index increment 就好。原因是因為慢慢的，該位置
//	  會被 res 指到，變成等著被覆蓋掉值的位置。

#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

class Solution2 {
public:
	int removeElement(vector<int>& nums, int val) {
		auto it = nums.begin();

		while (it != nums.end()) {
			if (*it == val) {
				nums.erase(it);
			}
			else {
				it++;
			}
		}

		return nums.size();
	}
};

class Solution3 {
public:
	int removeElement(vector<int>& nums, int val) {
		int res = 0;

		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != val) {
				nums[res] = nums[i];
				res++;
			}
		}

		return res;
	}
};

int main(int argc, char *argv[])
{
	Solution s1;
	Solution2 s2;
	Solution3 s3;
	vector<int> v1 = { 3,2,2,3 };
	vector<int> v2 = v1;
	vector<int> v3 = v2;

	cout << "size: " << s1.removeElement(v1, 3) << endl;
	cout << "size: " << s2.removeElement(v2, 3) << endl;
	cout << "size: " << s3.removeElement(v3, 3) << endl;

	return 0;
}