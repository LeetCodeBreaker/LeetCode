#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:

    bool containsNearbyDuplicate(const std::vector<int> &nums, const int &k) {
        std::unordered_map<int, unsigned int> num_map;
        for (unsigned int i = 0; i < nums.size(); i++) {
            auto it = num_map.find(nums[i]);
            if (it == num_map.end()) {
                num_map.insert({nums[i], i});
            } else {
                if (i - num_map[nums[i]] <= k) {
                    return true;
                } else {
                    it->second = i;
                }
            }
        }
        return false;
    }
};

int main() {
    Solution solution;
    std::cout << solution.containsNearbyDuplicate({1, 0, 1, 1}, 1) << std::endl;
    return 0;
}

