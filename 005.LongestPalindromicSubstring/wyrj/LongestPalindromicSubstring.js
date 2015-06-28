/* 180ms */
/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function(s) {
    var len = s.length, mid;
    var palLen = 0, palMid = -1, ret = '';
    var findPalindrome = function(str, start, end) {
        while(0 <= start && str.length > end && str[start] === str[end]) {
            start--;
            end++;
        }
        return end - start - 1;
    };
    for (mid = 0; mid < s.length; mid++) {
        var testLen = Math.max(findPalindrome(s, mid-1, mid+1), findPalindrome(s, mid, mid+1));
        if (testLen > palLen) {
            palLen = testLen;
            palMid = mid;
        }
        
    }
    return s.substr(palMid - Math.floor((palLen - 1) / 2), palLen);
};