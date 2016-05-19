#include <iostream>
#include <vector>
#include <unordered_set>

class Solution {
public:

    std::vector<int> intersection(const std::vector<int>& nums1, const std::vector<int>& nums2) {
        std::vector<int> answer;
        std::unordered_set<int> num_set(nums1.begin(), nums1.end());
        for (const auto &i : nums2) {
            if (num_set.find(i) != num_set.end()) {
                answer.push_back(i);
                num_set.erase(i);
            }
        }
        return answer;
    }
};

int main() {
    Solution solution;
    std::vector<int> test1{1, 2, 2, 1};
    std::vector<int> test2{2, 2};
    std::vector<int> answer = solution.intersection(test1, test2);

    for (const auto &i : answer) {
        std::cout << i << std::endl;
    }

    return 0;
}

