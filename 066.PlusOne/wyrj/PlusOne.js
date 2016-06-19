/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function(digits) {
    var i;
    for (i = digits.length - 1; i >= 0; i--) {
        if (9 !== digits[i]) {
            digits[i] += 1;
            break;
        } else {
            digits[i] = 0;
        }
    }
    if (i < 0) {
        digits.unshift(1);
    }
    return digits
};