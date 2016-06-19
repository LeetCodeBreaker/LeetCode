/**
 * @param {number[][]} matrix
 * @param {number} target
 * @return {boolean}
 */
var searchMatrix = function(matrix, target) {
    var m = matrix.length, n = matrix[0].length;
    var left = 0, right = m * n - 1;
    var mid, number;
    while(left <= right) {
        mid = Math.floor((left + right) / 2);
        number = matrix[Math.floor(mid / n)][mid % n];
        if (number === target) {
            return true;
        } else if (number > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return false;
};