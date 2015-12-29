#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int> &digits) {
        int index = digits.size() - 1;
        int carry = 1;
        do {
            if (digits[index] + carry > 9) {
                carry = 1;
                digits[index] = 0;
            } else {
                carry = 0;
                digits[index]++;
            }
            index--;
        } while (carry > 0 && index >= 0);
        if (carry > 0) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};

int main() {
    Solution solution;
    std::vector<int> nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(9);
    std::vector<int> numsPlusOne = solution.plusOne(nums);
    for (int i : numsPlusOne) {
        std::cout << i << ' ';
    }
    return 0;
}