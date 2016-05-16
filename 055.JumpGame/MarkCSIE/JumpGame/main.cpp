#include <iostream>
#include <vector>

class Solution {
public:

    bool canJump(const std::vector<int>& nums) {
        // vector<bool> table(nums.size(), false);
        // table[nums.size() - 1] = true;
        // for (int i = nums.size() - 2; i >= 0 ; i--) {
        //     for (int step = 1; step <= nums[i]; step++) {
        //         if (nums[i] - step <= nums[i + step]) {
        //             table[i] = table[i + step];
        //             break;
        //         } else if (i + step >= nums.size() || table[i + step]) {
        //             table[i] = true;
        //             break;
        //         }
        //     }
        // }
        // return table[0];

        if (nums.size() == 1) {
            return true;
        }
        int max_jump = 0;
        for (int i = 0; i < nums.size(); i++) {
            max_jump--;
            if (max_jump < nums[i])
                max_jump = nums[i];

            if (max_jump <= 0)
                return false;

            if (max_jump + i >= nums.size() - 1)
                return true;
        }
        return false;
    }
};

int main() {
    Solution solution;
    std::vector<int> test{2, 3, 1, 1, 4};
    std::cout << solution.canJump(test) << std::endl;

    return 0;
}

