/* 224ms */
/**
 * @param {number} x
 * @return {number}
 */
var reverse = function(x) {
    if (x < 0) {
        return -reverse(-x);
    }
    var ret = parseInt(x.toString().split('').reverse().join(''), 10);
    if (ret > -(1 << 31) - 1) {
        return 0;
    }
    return ret;
};