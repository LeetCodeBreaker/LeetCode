#include <iostream>

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return !(n & (n-1)) & (n > 0);
    }
};

int main() {
    Solution solution;
    std::cout << solution.isPowerOfTwo(4) << std::endl;
    return 0;
}

