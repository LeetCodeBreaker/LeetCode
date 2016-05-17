#include <iostream>
#include <vector>

class Solution {
public:

    int rob(std::vector<int>& nums) {
        if (nums.size() == 0) {
            return 0;
        }

        std::vector<int> table(nums.size(), 0);
        table[0] = nums[0];
        table[1] = std::max(nums[1], nums[0]);
        for (int i = 2; i < nums.size(); i++) {
            table[i] = std::max(nums[i] + table[i - 2], table[i - 1]);
        }
        return table[nums.size() - 1];
    }
};

int main() {
    Solution solution;
    std::vector<int> test{2, 3, 1, 1, 4};
    std::cout << solution.rob(test) << std::endl;

    return 0;
}

