#include <vector>
#include <algorithm>

class Solution {
public:

    std::vector<std::vector<int>> subsetsWithDup(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        return recursive(nums);
    }

    std::vector<std::vector<int>> recursive(std::vector<int>& nums) {
        std::vector<std::vector<int>> answer;
        std::vector<int> temp;
        answer.push_back(temp);

        for (int i = nums.size() - 1; i >= 0; i--) {
            int j = i - 1;
            while (j >= 0) {
                if (nums[j] != nums[i]) {
                    break;
                }
                j--;
            }
            std::vector<int> subNums(nums.begin(), nums.begin() + j + 1);

            std::vector<std::vector<int>> subAnswer = recursive(subNums);
            for (unsigned int k = 0; k < subAnswer.size(); ++k) {
                for (int l = j + 1; l <= i; ++l) {
                    subAnswer[k].push_back(nums[l]);
                }
            }

            answer.insert(std::end(answer), std::begin(subAnswer), std::end(subAnswer));
        }
        return answer;
    }
};

int main() {
    Solution solution;
    std::vector<int> testCase1{1, 2, 2};
    solution.subsetsWithDup(testCase1);
    return 0;
}