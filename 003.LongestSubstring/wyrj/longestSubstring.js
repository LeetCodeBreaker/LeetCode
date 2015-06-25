/* 188ms */
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function(s) {
    if ('' === s) {
        return 0;
    }
    var ans = 1;
    var length = 1;
    var begin = 0;
    for (var i = 1; i < s.length; i++) {
        var index = s.substr(begin, length).indexOf(s[i]);
        if (-1 < index) {
            index = index + begin;
            begin = index + 1;
            length = i - index;
        } else {
            length++;
            if (length > ans) {
                ans = length;
            }
        }
    }
    return ans;
};