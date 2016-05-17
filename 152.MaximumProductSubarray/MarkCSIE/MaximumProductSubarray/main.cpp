#include <iostream>
#include <vector>

class Solution {
public:

    int maxProduct(std::vector<int>& nums) {
        int max_local = nums[0];
        int min_local = nums[0];
        int answer = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            int temp = max_local;
            max_local = std::max(std::max(nums[i] * max_local, nums[i] * min_local), nums[i]);
            min_local = std::min(std::min(nums[i] * temp, nums[i] * min_local), nums[i]);
            answer = std::max(answer, max_local);
        }
        return answer;
    }
};

int main() {
    Solution solution;
    std::vector<int> test{2, 3, -2, 4};
    std::cout << solution.maxProduct(test) << std::endl;

    return 0;
}

