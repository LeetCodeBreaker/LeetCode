/* 132ms */
/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    var i = 0, j = height.length - 1;
    var ret = 0;
    while(i < j) {
        var c = Math.min(height[i], height[j]) * (j - i);
        if (c > ret) {
            ret = c;
        }
        (height[i] > height[j]) ? j-- : i++;
    }
    return ret;
};