/* 124ms */
/**
 * @param {number} n
 * @return {string[]}
 */
var generateParenthesis = function(n) {
    var ret = [];
    var recursive = function(left, right, str) {
        if (0 === left) {
            while (right--) {
                str += ')';
            }
            ret.push(str);
            return ;
        }
        recursive(left - 1, right, str + '(');
        if (left < right) {
            recursive(left, right - 1, str + ')');
        }
    };
    recursive(n, n, '');
    return ret;
};