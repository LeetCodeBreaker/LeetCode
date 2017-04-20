#include <iostream>
#include <vector>

class Solution {
public:

    int maxRotateFunction(const std::vector<int> &A) {
        if (A.size() == 0) {
            return 0;
        }
        int F = 0;
        int sum_A = 0;
        for (size_t i = 0; i < A.size(); i++) {
            F += i * A[i];
            sum_A += A[i];
        }

        int max_F = F;
        for (size_t i = 1; i < A.size(); i++) {
            F += sum_A - A.size() * A[A.size() - i];
            max_F = std::max(F, max_F);
        }
        return max_F;
    }
};

int main() {
    Solution solution;
    std::cout << solution.maxRotateFunction({4, 3, 2, 6}) << std::endl;
    return 0;
}

