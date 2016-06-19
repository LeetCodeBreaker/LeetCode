/**
 * @param {number[][]} grid
 * @return {number}
 */
var minPathSum = function(grid) {
    var table = [], m = grid.length, n = grid[0].length, i, j;
    table[0] = [grid[0][0]];
    for (i = 1; i < m; i++) {
        table[i] = [grid[i][0] + table[i - 1][0]];
    }
    for (j = 1; j < n; j++) {
        table[0][j] = grid[0][j] + table[0][j - 1];
    }
    for (i = 1; i < m; i++) {
        for (j = 1; j < n; j++) {
            table[i][j] = grid[i][j] + Math.min(table[i - 1][j], table[i][j - 1]);
        }
    }
    return table[m - 1][n - 1];
};