#include <iostream>
#include <vector>

class Solution {
public:

    int minPathSum(std::vector<std::vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();

        int **valueGrid = new int*[m];
        for (int i = 0; i < m; i++) {
            valueGrid[i] = new int[n];
        }

        valueGrid[0][0] = grid[0][0];
        for (int i = 1; i < n; i++) {
            valueGrid[0][i] = grid[0][i] + valueGrid[0][i - 1];
        }

        for (int i = 1; i < m; i++) {
            valueGrid[i][0] = grid[i][0] + valueGrid[i - 1][0];
            for (int j = 1; j < n; j++) {
                valueGrid[i][j] = grid[i][j] + std::min(valueGrid[i - 1][j], valueGrid[i][j - 1]);
            }
        }
        int answer = valueGrid[m - 1][n - 1];

        for (int i = 0; i < m; i++) {
            delete [] valueGrid[i];
        }
        delete [] valueGrid;

        return answer;
    }
};

int main() {
    Solution solution;
    std::vector<std::vector<int> > obstacleGrid;
    std::vector<int> obstacleArray;
    obstacleArray.push_back(0);
    obstacleGrid.push_back(obstacleArray);
    obstacleGrid.push_back(obstacleArray);
    std::cout << solution.minPathSum(obstacleGrid) << std::endl;
    return 0;
}