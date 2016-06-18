/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function(matrix) {
    if (0 === matrix.length || 0 === matrix[0].length) {
        return [];
    }
    var m = matrix.length, n = matrix[0].length;
    var result = [matrix[0][0]];
    var nextCoord = [function(coord) {
        coord.col += 1;
    }, function(coord) {
        coord.row += 1;
    }, function(coord) {
        coord.col -= 1;
    }, function(coord) {
        coord.row -= 1;
    }];
    var walls = [n - 1, m - 1, 0, 0];
    var coord = {row: 0, col: 0}, dir = (n > 1) ? 0 : 1;
    while(result.length < m * n) {
        nextCoord[dir](coord);
        result.push(matrix[coord.row][coord.col]);
        if (coord[(dir % 2 === 0) ? 'col' : 'row'] === walls[dir]) {
            walls[(dir + 3) % 4] += ((((dir + 3) % 4) >= 2) ? 1 : -1);
            dir = (dir + 1) % 4;
        }
    }
    return result;
};