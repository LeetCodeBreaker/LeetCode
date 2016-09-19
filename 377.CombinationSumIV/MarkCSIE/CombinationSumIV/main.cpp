#include <iostream>
#include <vector>
#include <map>

class Solution {
public:

    std::size_t combinationSum4(const std::vector<int>& nums, const int &target) {
        if (target == 0) {
            return 1;
        } else if (target < 0) {
            return 0;
        }
        std::size_t answer = 0;
        for (const auto &i : nums) {
            if (memo.find(target - i) == memo.end()) {
                memo[target - i] = combinationSum4(nums, target - i);
            }
            answer += memo[target - i];

        }
        return answer;
    }
private:
    std::map<int, std::size_t> memo;
};

int main() {
    Solution solution;
    std::cout << solution.combinationSum4({1, 2, 3}, 4) << std::endl;
    return EXIT_SUCCESS;
}

