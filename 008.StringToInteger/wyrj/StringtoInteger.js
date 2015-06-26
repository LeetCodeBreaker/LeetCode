/* 208ms */
/**
 * @param {string} str
 * @return {number}
 */
var myAtoi = function(str) {
    var INT_MAX = 2147483647, INT_MIN = -2147483648;
    str = str.trimLeft();
    var j = 1;
    while('0' <= str[j] && '9' >= str[j]) {
        j++;
    }
    var ret = parseInt(str.slice(0, j), 10);
    return (isNaN(ret)) ? 0 : (ret > INT_MAX) ? INT_MAX : (ret < INT_MIN) ? INT_MIN : ret;
};