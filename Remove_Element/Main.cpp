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
// �D�`�맮�� "�ֺC�����w" �Ѫk
// �򥻷����O:
// 1. �Τ@���ܼ� (res) �����Ʊ�:
//		# �����b vector ���A�ثe�i�H"�Q�л\����"����m (�]�N�O���A�o�� res �ҫ�����m���ȡA�ڭ̤w�g�T�w���n�F)
//		# �P�ɤ]�O���F�̫�n��X��"�������n��X������"���᪺ vector ������ (�]���b�L���e�������A�ڭ̳��w�g�T�w�n�O�d)
//
//		�o���ܼƩҥN���N�q�A���F�W��������إ\�ध�~�A�]�Хܵۦb�Ӧ�m���e�������A���O�w�g�T�w�n�O�d������ (�P�W��2�I)
//		�`�N�Ares �i�H��ª� increment by 1, �]��res�᭱���ȡA�p�G���ݭn�Q�O�d���A���w�g�Q�ƻs��e������m�h�F�A�ҥH�ڭ̤���
//		��� res++ �|�ɭP�Y�ǭn�O�d���ȷ|�Q�\���C
// 2. �Υt�@���ܼ� i ��@ index �h�@�Ӥ@�Ӫ� traverse vector ��������
// 3. �� nums[i] �����ȡA���O�ڭ̷Q�n�ư����Ȫ��ɭԡA�ڭ̭n�O�d nums[i]�A�]���� nums[i] �����л\�� nums[res] �h�A�]�� res
//    �ХܤF�ثe�i�H�Q�л\����m�C
// 4. �� nums[i] �����ȵ���ڭ̭n�ư����Ȫ��ɭԡA�ϦӬƻ򳣤��ΰ��A�u�ݭn�� index increment �N�n�C��]�O�]���C�C���A�Ӧ�m
//	  �|�Q res ����A�ܦ����۳Q�л\���Ȫ���m�C

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