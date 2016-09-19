#include <iostream>

class Solution {
public:

    uint32_t reverseBits(uint32_t n) {
        uint32_t answer = n & 1;
        for (int i = 0; i < 31; i++) {
            answer = answer << 1;
            n = n >> 1;
            answer += n & 1;
        }
        return answer;

        // Optimization: create a table. table[num] = reversed_bits_num
    }
};

int main() {
    Solution solution;
    uint32_t answer = solution.reverseBits(1);
    std::cout << answer << std::endl;
    return 0;
}

