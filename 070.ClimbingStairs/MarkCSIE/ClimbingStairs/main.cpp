#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        int *O = new int[n];
        O[0] = 1;
        O[1] = 2;
        for (int i = 2; i < n; i++) {
            O[i] = O[i-1] + O[i-2];
        }
        return O[n-1];
    }
};

int main() {
    Solution solution;
    std::cout << solution.climbStairs(16) << std::endl;
    return 0;
}