/* 220ms */
/**
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function(s, numRows) {
    if (1 === numRows) {
        return s;
    }
    var ret = '';
    for (var i = 0; i < numRows; i++) {
        var j = i;
        var next = [2*(numRows-i) - 3, 2*i - 1];
        if (next[0] < 0) {
            next[0] = next[1];
        } else if (next[1] < 0) {
            next[1] = next[0];
        }
        var flag = 0;
        while (j < s.length) {
            ret += s[j];
            j += next[flag % 2] + 1;
            flag++;
        }
    }
    return ret;
};