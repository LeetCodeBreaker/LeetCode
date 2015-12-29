#include <iostream>
#include <vector>

class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int> >& obstacleGrid) {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        
        int **grid = new int*[m];
        for(int i = 0; i < m; i++) {
            grid[i] = new int[n];
        }

        if (obstacleGrid[0][0] == 0) {
            grid[0][0] = 1;
        } else {
            grid[0][0] = 0;
        }
        
        for (int i = 1; i < n; i++) {
            if (obstacleGrid[0][i] == 0){
                grid[0][i] = grid[0][i-1];
            } else {
                grid[0][i] = 0;
            }
        }
        for (int i = 1; i < m; i++) {
            if (obstacleGrid[i][0] == 0) {
                grid[i][0] = grid[i-1][0];
            } else {
                grid[i][0] = 0;
            }
            for (int j = 1; j < n; j++) {
                if (obstacleGrid[i][j] == 0) {
                    grid[i][j] = grid[i-1][j] + grid[i][j-1];
                } else {
                    grid[i][j] = 0;
                }
            }
        }
        int answer = grid[m-1][n-1];
        
        for(int i = 0; i < m; i++) {
            delete [] grid[i];
        }
        delete [] grid;
        
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
    std::cout << solution.uniquePathsWithObstacles(obstacleGrid) << std::endl;
    return 0;
}