#include <iostream>
#include <unordered_set>

class Solution {
public:

    bool isHappy(int n) {
        std::unordered_set<int> num_set;
        while (num_set.find(n) == num_set.end()) {
            num_set.insert(n);
            int sum = 0;
            while (n > 0) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            n = sum;
        }
        if (n == 1) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    Solution solution;
    std::cout << solution.isHappy(19) << std::endl;
    return 0;
}

