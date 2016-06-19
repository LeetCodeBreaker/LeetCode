/**
 * @param {number} n
 * @return {number}
 */
var climbStairs = function(n) {
    var table = [1, 1], i;
    for (i = 2; i <= n; i++) {
        table[i] = table[i - 1] + table[i - 2];
    }
    return table[n];
};