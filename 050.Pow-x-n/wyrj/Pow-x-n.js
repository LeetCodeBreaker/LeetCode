/**
 * @param {number} x
 * @param {number} n
 * @return {number}
 */
var myPow = function(x, n) {
    if (n < 0) {
        return 1 / myPow(x, -n);
    }
    if (0 === n) {
        return 1;
    }
    var sq;
    if (0 === n % 2) {
        return myPow(x * x, Math.floor(n / 2));
    } else {
        return myPow(x * x, Math.floor(n / 2)) * x;
    }
};