#include <iostream>
#include <cmath>

class Solution {
public:
    int mySqrt(int x) {
        // Newton's method
        double x0 = 1;
        while (true) {
            double x1 = x0 - (x0*x0 - x) / (2 * x0);
            if (x1 * x1 == x || std::fabs(x0 - x1) < 1) {
                return static_cast<int>(x1);
            }
            x0 = x1;
        }
    }
};

int main() {
    Solution solution;
    std::cout << solution.mySqrt(16) << std::endl;
    return 0;
}

