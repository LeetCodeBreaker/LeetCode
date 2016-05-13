#include <iostream>
#include <vector>

class Solution {
public:

    bool searchMatrix(const std::vector<std::vector<int>> &matrix, const int &target) {
        int m = matrix.size();
        int n = matrix[0].size();

        int i = 0;
        int j = n - 1;
        while (true) {
            if (matrix[i][j] > target) {
                j--;
            } else if (matrix[i][j] < target) {
                i++;
            } else {
                return true;
            }

            if (i == m || j == -1) {
                break;
            }
        }
        return false;
    }
};

int main() {
    std::vector<std::vector<int>> test = {
        {1, 4, 7, 11, 15},
        {2, 5, 8, 12, 19},
        {3, 6, 9, 16, 22},
        {10, 13, 14, 17, 24},
        {18, 21, 23, 26, 30}
    };
    Solution solution;
    std::cout << solution.searchMatrix(test, 5) << std::endl;
    return 0;
}

