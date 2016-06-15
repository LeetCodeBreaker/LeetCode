/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function(matrix) {
    var n = matrix.length;
    var row = Math.floor(n / 2);
    var col = Math.ceil(n / 2);
    var i, j, coord, nextCoord;
    var rotate = function(c) {
        return [n - c[1] - 1, c[0]];
    }
    var swap = function(c1, c2) {
        var temp = matrix[c1[0]][c1[1]];
        matrix[c1[0]][c1[1]] = matrix[c2[0]][c2[1]];
        matrix[c2[0]][c2[1]] = temp;
    }
    for (i = 0; i < row; i++) {
        for (j = 0; j < col; j++) {
            coord = [i, j];
            nextCoord = rotate(coord);
            while(nextCoord[0] !== i || nextCoord[1] !== j) {
                swap(coord, nextCoord);
                coord = nextCoord;
                nextCoord = rotate(coord);
            }
        }
    }
};