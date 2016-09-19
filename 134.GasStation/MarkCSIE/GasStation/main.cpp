#include <iostream>
#include <vector>

class Solution {
public:

    int canCompleteCircuit(const std::vector<int> &gas, const std::vector<int> &cost) {
        int sumRemaining = 0;
        int total = 0;
        size_t start = 0;

        for (size_t i = 0; i < gas.size(); i++) {
            int remaining = gas[i] - cost[i];

            if (sumRemaining >= 0) {
                sumRemaining += remaining;
            } else {
                sumRemaining = remaining;
                start = i;
            }
            total += remaining;
        }

        if (total >= 0) {
            return start;
        } else {
            return -1;
        }
    }
};

int main() {
    Solution solution;
    std::cout << solution.canCompleteCircuit({1, 2}, {2, 1}) << std::endl;
    return 0;
}

