#include <iostream>
#include <vector>

class Solution {
public:

    std::vector<int> singleNumber(std::vector<int>& nums) {
        std::vector<int> answer(2, 0);

        int xor_value = 0;
        for (int i = 0; i < nums.size(); i++) {
            xor_value ^= nums[i];
        }

        int bit1_pos = 0;
        for (int i = 0; i < 32; i++) {
            if (xor_value >> i & 1 == 1) {
                bit1_pos = i;
                break;
            }
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] >> bit1_pos & 1 == 1) {
                answer[0] ^= nums[i];
            } else {
                answer[1] ^= nums[i];
            }
        }

        return answer;
    }
};

int main() {
    Solution solution;
    std::vector<int> test{1, 2, 1, 3, 2, 5};
    std::vector<int> answer = solution.singleNumber(test);
    for (int i : answer) {
        std::cout << i << std::endl;
    }

    return 0;
}

