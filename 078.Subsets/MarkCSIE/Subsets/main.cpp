#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return recursive(nums);
    }
    
    std::vector<std::vector<int>> recursive(std::vector<int>& nums) {
        std::vector<std::vector<int>> answer;
        std::vector<int> temp;
        answer.push_back(temp);
        
        for (int i = nums.size() - 1; i >= 0; i--) {            
            std::vector<int> subNums(nums.begin(), nums.begin() + i);
            
            std::vector<std::vector<int>> subAnswer = recursive(subNums);
            for (int j = 0; j < subAnswer.size(); j++) {
                subAnswer[j].push_back(nums[i]);
            }
            
            answer.insert(std::end(answer), std::begin(subAnswer), std::end(subAnswer));
        }
        return answer;
    }
};

int main() {
    Solution solution;
    std::vector<int> testCase1{1,2,3,4,5,6,7,8,10,0};
    solution.subsets(testCase1);
    return 0;
}