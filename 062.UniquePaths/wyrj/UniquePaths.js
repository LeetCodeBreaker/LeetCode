/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var uniquePaths = function(m, n) {
    var table = [], i, j;
    for (i = 0; i < m; i++) {
        table[i] = [];
        for (j = 0; j < n; j++) {
            if (0 === i || 0 === j) {
                table[i][j] = 1;
            } else {
                table[i][j] = table[i - 1][j] + table[i][j - 1];
            }
        }
    }
    return table[m - 1][n - 1];
};