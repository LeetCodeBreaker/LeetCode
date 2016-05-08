/**
 * @param {number[]} candidates
 * @param {number} target
 * @return {number[][]}
 */
var combinationSum2 = function(candidates, target) {
    var i, j, k, back, temp;
    var table = [];
    candidates.sort(function(lhs, rhs) {
        return lhs - rhs;
    });
    for (i = 1; i <= target; i++) {
        table[i] = [];
        for (j = 0; j < candidates.length; j++) {
            table[i][j] = [];
            n = candidates[j];
            if (0 < j) {
                if (candidates[j - 1] !== n) {
                    table[i][j] = table[i][j - 1].slice(0);   
                } else {
                    for (k = 0; k < table[i][j - 1].length; k++) {
                        temp = table[i][j - 1][k];
                        if (temp[temp.length - 1] !== n) {
                            table[i][j].push(temp);
                        }
                    }
                }
            }
            if (n > i) {
                continue;
            } else if (n === i) {
                table[i][j].push([n]);
            } else if (0 !== j) {
                back = table[i - n][j - 1];
                for (k = 0; k < back.length; k++) {
                    temp = back[k].slice(0);
                    temp.push(n);
                    table[i][j].push(temp);
                }
            }
        }
    }
    return table[target][candidates.length - 1];
};