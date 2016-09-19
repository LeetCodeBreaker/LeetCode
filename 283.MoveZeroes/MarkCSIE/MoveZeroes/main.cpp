#include <iostream>
#include <vector>
#include <queue>

class Solution {
public:

    void moveZeroes(std::vector<int>& nums) {
        std::queue<int> zero_index_queue;
        for (std::size_t i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                zero_index_queue.push(i);
            } else {
                if (!zero_index_queue.empty()) {
                    std::swap(nums[i], nums[zero_index_queue.front()]);
                    zero_index_queue.pop();
                    zero_index_queue.push(i);
                }
            }
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> test = {0, 1, 0, 3, 12};
    solution.moveZeroes(test);
    for (const auto &i : test) {
        std::cout << i << std::endl;
    }
    return 0;
}

