#include <iostream>
#include <vector>
#include <limits>

class Solution {
public:

    bool increasingTriplet(const std::vector<int>& nums) {
        int first_max = findMax(nums, nums.size() - 1);
        if (first_max > 1) {
            int second_max = findMax(nums, first_max - 1);
            if (second_max > 0) {
                int third_max = findMax(nums, second_max - 1);
                if (nums[third_max] < nums[second_max]) {
                    return true;
                }
            }
        }

        int first_min = findMin(nums, 0);
        if (first_min < nums.size() - 2) {
            int second_min = findMin(nums, first_min + 1);
            if (second_min < nums.size() - 1) {
                int third_min = findMin(nums, second_min + 1);
                if (nums[third_min] > nums[second_min]) {
                    return true;
                }
            }
        }

        return false;
    }

private:

    int findMax(const std::vector<int>& nums, const int &start_index) {
        int max = std::numeric_limits<int>::min();
        int max_index = -1;

        for (int i = start_index; i >= 0; i--) {
            if (nums[i] >= max) {
                max = nums[i];
                max_index = i;
            }
        }
        return max_index;
    }

    int findMin(const std::vector<int>& nums, const int &start_index) {
        int min = std::numeric_limits<int>::max();
        int min_index = -1;

        for (int i = start_index; i < nums.size(); i++) {
            if (nums[i] <= min) {
                min = nums[i];
                min_index = i;
            }
        }
        return min_index;
    }
};

int main() {
    Solution solution;

    std::vector<int> test{1, 2, 3, 4, 5};
    std::cout << solution.increasingTriplet(test) << std::endl;

    return 0;
}

