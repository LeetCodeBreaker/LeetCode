/* 128ms */
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function(digits) {
    if ('' === digits) {
        return [];
    }
    var ret = [];
    var translator = {'2': 'abc', '3': 'def', '4': 'ghi', '5': 'jkl', '6': 'mno', '7': 'pqrs', '8': 'tuv', '9': 'wxyz'};
    var recursive = function(str, index) {
        if (index === digits.length) {
            ret.push(str);
            return ;
        }
        var clone = str.substr(0);
        for (var i = 0; i < translator[digits[index]].length; i++) {
            recursive(str + translator[digits[index]][i], index + 1);
        }
    };
    recursive('', 0);
    return ret;
};