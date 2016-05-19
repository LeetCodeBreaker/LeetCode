#include <iostream>
#include <vector>

class Solution {
public:

    int findMin(const std::vector<int>& nums) {
        // O(n)
        // for (int i = 0; i < nums.size() - 1; i++) {
        //     if (nums[i + 1] < nums[i]) {
        //         return nums[i + 1];
        //     }
        // }
        // return nums[0];

        // O(logn)
        int left = 0;
        int right = nums.size() - 1;
        while (true) {
            int mid = (left + right) / 2;
            if ((nums[mid] < nums[mid - 1] && nums[mid] < nums[mid + 1]) || left >= right) {
                return nums[mid];
            } else if (nums[mid] > nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
};

int main() {
    Solution solution;
    std::vector<int> test{4, 5, 6, 7, 0, 1, 2};
    std::cout << solution.findMin(test) << std::endl;

    return 0;
}

