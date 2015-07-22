/* 140ms */
/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function(haystack, needle) {
    var backward = [], i = 0, j;
    backward[0] = -1;
    for (j = 1; j < needle.length; j++) {
        if (needle[j] === needle[i]) {
            backward[j] = i;
            i++;
        } else {
            backward[j] = -1;
            i = 0;
        }
    }
    i = 0;
    j = 0;
    while (true) {
        if (j === needle.length) {
            return i - needle.length;
        } else if (i === haystack.length) {
            return -1;
        } else if (haystack[i] === needle[j]) {
            i++;
            j++;
        } else if (0 !== j) {
            j = backward[j-1]+1;
        } else {
            i++;
        }
    }
};