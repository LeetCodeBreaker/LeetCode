#include <vector>
#include <iostream>

class Solution {
public:

    int minimumTotal(std::vector<std::vector<int>>&triangle) {
        int n = triangle.size();
        int *table = new int[n];
        for (int i = 0; i < n; i++) {
            table[i] = triangle[n - 1][i];
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j < i + 1; j++) {
                table[j] = std::min(table[j], table[j + 1]) + triangle[i][j];
            }
        }

        int answer = table[0];
        delete [] table;
        return answer;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int>> test{{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};

    std::cout << solution.minimumTotal(test) << std::endl;
    return 0;
}

