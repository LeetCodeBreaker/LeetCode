#include <vector>
#include <iostream>

class Solution {
public:

    std::vector<int> productExceptSelf(const std::vector<int>& nums) {
        std::vector<int> ans(nums.size(), 1);
        int product = 1;
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = product;
            product *= nums[i];
        }

        product = 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            ans[i] *= product;
            product *= nums[i];
        }

        return ans;
    }
};

int main() {
    Solution solution;
    std::vector<int> test{1, 2, 3, 4};
    for (const int &i : solution.productExceptSelf(test)) {
        std::cout << i << std::endl;
    }
    return 0;
}

