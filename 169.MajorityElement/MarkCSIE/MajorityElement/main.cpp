#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:

    int majorityElement(const std::vector<int> &nums) {
        std::unordered_map<int, size_t> count_map;
        size_t max = 0;
        size_t max_index = 0;
        for (const auto &i : nums) {
            if (count_map.find(i) == count_map.end()) {
                count_map[i] = 1;
            } else {
                count_map[i]++;
            }
            if (count_map[i] > max) {
                max_index = i;
                max = count_map[i];
            }
        }
        return max_index;
    }
};

int main() {
    Solution solution;
    std::cout << solution.majorityElement({1, 2}) << std::endl;
    return 0;
}

