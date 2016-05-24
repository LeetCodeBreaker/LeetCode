#include <iostream>
#include <cmath>

class Solution {
public:

    bool isPowerOfFour(const int &num) {
        if (num == 0) {
            return false;
        }
        double log4 = std::log(num) / std::log(4);
        double int_part;
        double fraction_part = std::modf(log4, &int_part);
        if (fraction_part == 0) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution solution;
    std::cout << solution.isPowerOfFour(16) << std::endl;
    return 0;
}

