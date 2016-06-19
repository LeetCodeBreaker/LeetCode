/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function(matrix) {
    var row = [], col = [], i, j, k;
    for (i = 0; i < matrix.length; i++) {
        for (j = 0; j < matrix[i].length; j++) {
            if (matrix[i][j] === 0) {
                if (!row[i]) {
                    for (k = 0; k < j; k++) {
                        matrix[i][k] = 0;
                    }
                    row[i] = true;
                }
                if (!col[j]) {
                    for (k = 0; k < i; k++) {
                        matrix[k][j] = 0;
                    }
                    col[j] = true;
                }
            } else if (row[i] || col[j]) {
                matrix[i][j] = 0;
            }
        }
    }
};