/* 784ms */
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function(x) {
    if (0 > x) {
        return false;
    }
    var arr = [];
    while(0 < x) {
        arr.push(x%10);
        x = Math.floor(x/10);
    }
    var start = 0, end = arr.length - 1;
    while(start < end) {
        if (arr[start] !== arr[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
};