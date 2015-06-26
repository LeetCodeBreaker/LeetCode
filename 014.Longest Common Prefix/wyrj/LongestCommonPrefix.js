/* 136ms */
/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function(strs) {
    if (0 === strs.length) {
        return '';
    }
    var ret = '', index = 0;
    while(true) {
        if (index === strs[0].length) {
            return ret;
        }
        var n = strs[0][index];
        for (var i = 1; i < strs.length; i++) {
            if (index === strs[i].length || n !== strs[i][index]) {
                return ret;
            }
        }
        ret += n;
        index++;
    }
};