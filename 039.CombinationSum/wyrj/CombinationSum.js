/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum = function(candidates, target) {
    var result = [];
    var i, j, n, table = [];
    candidates.sort(function(lhs, rhs) {
        return lhs - rhs;
    });
    for (i = 1; i <= target; i++) {
        table[i] = [];
        for (j = 0; j < candidates.length; j++) {
            n = candidates[j];
            if (n > i) {
                break;
            } else if (n === i) {
                table[i].push([n])
            } else if (0 < table[i - n].length) {
                for (k = 0; k < table[i - n].length; k++) {
                    if (table[i - n][k][table[i - n][k].length - 1] <= n) {
                        table[i].push(table[i - n][k].slice(0));
                        table[i][table[i].length - 1].push(n);
                    }
                }
            }
        }
    }
    return table[target];
};