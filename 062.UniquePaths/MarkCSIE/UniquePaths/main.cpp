#include <iostream>

class Solution {
public:
    int uniquePaths(int m, int n) {
        int **grid = new int*[m];
        for(int i = 0; i < m; i++) {
            grid[i] = new int[n];
        }
        for (int i = 0; i < n; i++) {
            grid[0][i] = 1;
        }
        for (int i = 1; i < m; i++) {
            grid[i][0] = grid[i-1][0];
            for (int j = 1; j < n; j++) {
                grid[i][j] = grid[i-1][j] + grid[i][j-1];
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
    std::cout << solution.uniquePaths(3, 7) << std::endl;
    return 0;
}