#include <iostream>
#include <vector>

class NumArray {
public:
    std::vector<int> sum;

    NumArray(std::vector<int> &nums) {
        if (nums.size() > 0) {
            sum.push_back(nums[0]);
            for (int i = 1; i < nums.size(); i++) {
                sum.push_back(sum.back() + nums[i]);
            }
        }
    }

    int sumRange(int i, int j) {
        if (i == 0) {
            return sum[j];
        } else {
            return sum[j] - sum[i - 1];
        }
    }
};

int main() {
    std::vector<int> nums{-2, 0, 3, -5, 2, -1};
    NumArray numArray(nums);
    std::cout << numArray.sumRange(0, 2) << std::endl;
    std::cout << numArray.sumRange(2, 5) << std::endl;
    std::cout << numArray.sumRange(0, 5) << std::endl;

    return 0;
}

