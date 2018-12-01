/**
 * @param {number} n
 * @param {number} k
 * @return {number[][]}
 */
var combine = function(n, k) {
    if (k === 1) {
        return new Array(n).fill(0).map((a, i) => [i + 1]);
    } else if (n === k) {
        return [new Array(n).fill(0).map((a, i) => i + 1)];
    }
    return combine(n - 1, k - 1).map(a => {a.push(n); return a;}).concat(combine(n - 1, k));
};
