/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var multiply = function(num1, num2) {
    if ('0' === num1 || '0' === num2) {
        return '0';
    }
    var str2big = function(str) {
        var big = [];
        var n = str.length;
        while (0 < n) {
            len = Math.min(n, 5);
            big.push(parseInt(str.substr(n - len, len), 10));
            n -= len;
        }
        return big;
    }
    var fill = function(num) {
        var s = num.toString();
        while (s.length < 5) {
            s = '0' + s;
        }
        return s;
    }
    var big1 = str2big(num1);
    var big2 = str2big(num2);
    var ans = [], i, j, n, result;
    for (i = 0; i < big1.length; i++) {
        for (j = 0; j < big2.length; j++) {
            n = big1[i] * big2[j];
            ans[i + j] = (ans[i + j] || 0) + n;
        }
    }
    for (i = 0; i < ans.length; i++) {
        if (99999 < ans[i]) {
            ans[i + 1] = (ans[i + 1] || 0) + Math.floor(ans[i] / 100000);
            ans[i] = ans[i] % 100000;
        }
    }
    result = '' + ans[ans.length - 1];
    for (i = ans.length - 2; i >= 0; i--) {
        result += fill(ans[i]);
    }
    return result;
};