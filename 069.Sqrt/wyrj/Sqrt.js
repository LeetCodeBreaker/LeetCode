/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function(x) {
    var left = 0, mid, right = x;
    while(left <= right) {
        mid = Math.floor((left + right) / 2);
        if (mid * mid <= x && (mid + 1)*(mid + 1) > x) {
            return mid;
        } else if (mid * mid > x) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return mid;
};