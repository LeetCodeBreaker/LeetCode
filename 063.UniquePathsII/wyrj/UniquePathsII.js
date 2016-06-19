/**
 * @param {number[][]} obstacleGrid
 * @return {number}
 */
var uniquePathsWithObstacles = function(obstacleGrid) {
    var table = [], i, j, m = obstacleGrid.length, n = obstacleGrid[0].length;
    table[0] = [1 - obstacleGrid[0][0]];
    for (i = 1; i < m; i++) {
        table[i] = [];
        table[i][0] = (obstacleGrid[i][0]) ? 0 : table[i - 1][0];
    }
    for (j = 1; j < n; j++) {
        table[0][j] = (obstacleGrid[0][j]) ? 0 : table[0][j - 1];
    }
    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            if (obstacleGrid[i][j]) {
                table[i][j] = 0;
            } else {
                table[i][j] = table[i - 1][j] + table[i][j - 1];
            }
        }
    }
    return table[m - 1][n - 1];
};