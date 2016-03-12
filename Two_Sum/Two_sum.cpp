#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;

        for(int i = 0; i <= (nums.size() - 2); i++) {
            for(int j = i + 1; j <= (nums.size() - 1); j++) {
                int sum = nums[i] + nums[j];
                if(sum == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }

    }
};

int main() {
    Solution solution;

    vector<int> input;
    input.push_back(2);
    input.push_back(7);
    input.push_back(11);
    input.push_back(15);

    vector<int> answer = solution.twoSum(input, 9);

    cout << "[";
    for(int i = 0; i < (answer.size()-1); i++) {
        cout << answer[i] << ", ";
    }
    cout << answer[answer.size()-1];
    cout << "]";
}