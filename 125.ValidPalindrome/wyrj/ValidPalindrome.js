/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function(s) {
    s = s.toLowerCase().split(/[^0-9a-z]/).filter(a => a.length > 0).join('');
    return s === s.split('').reverse().join('');
};
