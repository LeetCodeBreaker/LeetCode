#include <iostream>
#include <cmath>

class Solution {
public:

    int integerBreak(int n) {
        // DP: O(n^2)
        int *table = new int[n + 1];
        table[0] = 0;
        table[1] = 1;

        for (int i = 2; i <= n; i++) {
            int max = -1;
            for (int j = 1; j <= i / 2; j++) {
                if (j * table[i - j] > max) {
                    max = j * table[i - j];
                }
                if (j * (i - j) > max) {
                    max = j * (i - j);
                }
            }
            table[i] = max;
        }

        int answer = table[n];
        delete [] table;
        return answer;

        // Math: O(1)
        if (n <= 3) {
            return n - 1;
        }
        if (n % 3 == 0) {
            return std::pow(3, n / 3);
        } else if (n % 3 == 1) {
            return 2 * 2 * std::pow(3, (n - 4) / 3);
        } else {
            return 2 * std::pow(3, (n - 2) / 3);
        }
    }
};

int main() {
    Solution solution;
    std::cout << solution.integerBreak(10) << std::endl;
    return 0;
}

