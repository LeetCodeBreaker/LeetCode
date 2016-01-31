#include <iostream>
#include <vector>

class Solution {
public:

    int missingNumber(std::vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            sum += nums[i];
        }
        return n * (n + 1) / 2 - sum;
        
        // Bit operation: answer xor nums xor i
    }
};

int main() {
    Solution solution;
    std::vector<int> test{0, 1, 3};
    std::cout << solution.missingNumber(test) << std::endl;
    return 0;
}

