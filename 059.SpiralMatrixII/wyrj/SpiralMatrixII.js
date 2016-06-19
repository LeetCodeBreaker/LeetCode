/**
 * @param {number} n
 * @return {number[][]}
 */
var generateMatrix = function(n) {
    var matrix = [], i;
    for (i = 0; i < n; i++) {
        matrix[i] = [];
    }
    i = 1, row = 0, col = -1, dir = 'right';
    while (i <= n * n) {
        if ('right' === dir) {
            if (col + 1 === n || matrix[row][col + 1]) {
                dir = 'down';
                continue;
            }
            col += 1;
        } else if ('down' === dir) {
            if (row + 1 === n || matrix[row + 1][col]) {
                dir = 'left';
                continue;
            }
            row += 1;
        } else if ('left' === dir) {
            if (col === 0 || matrix[row][col - 1]) {
                dir = 'up';
                continue;
            }
            col -= 1;
        } else if ('up' === dir) {
            if (matrix[row - 1][col]) {
                dir = 'right';
                continue;
            }
            row -= 1;
        }
        matrix[row][col] = i;
        i += 1;
    }
    return matrix;
};