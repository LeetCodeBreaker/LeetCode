/**
 * @param {number} n
 * @param {number} k
 * @return {string}
 */
var getPermutation = function(n, k) {
    var option = [], factor = [1], i, index, result = '';
    for (i = 1; i <= n; i++) {
        option[i] = i;
        factor[i] = factor[i - 1] * i;
    }
    for (i = 0; i < n; i++) {
        index = Math.ceil(k / factor[n - i - 1]);
        result += option[index];
        option.splice(index, 1);
        k -= ((index - 1) * factor[n - i - 1]);
    }
    return result;
};