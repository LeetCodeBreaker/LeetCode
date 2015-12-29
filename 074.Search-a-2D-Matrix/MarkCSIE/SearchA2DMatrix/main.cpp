#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        int lowerBound = 0;
        int upperBound = matrix.size()-1;
        int i = (lowerBound+upperBound)/2;
        while (true) {
            if (lowerBound > upperBound) {
                for (int j = 1; j < n; j++) {
                    if (matrix[i][j] == target) {
                        return true;
                    }
                }
                return false;
            }
            if (matrix[i][0] == target) {
                return true;
            } else if (matrix[i][0] > target) {
                upperBound = i-1;
                i = (lowerBound+upperBound)/2;
            } else {
                lowerBound = i+1;
                i = (lowerBound+upperBound)/2;
            }
        }
        return false;
    }
};

int main() {
    Solution solution;

    return 0;
}