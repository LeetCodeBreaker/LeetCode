/**
 * @param {number[]} nums
 * @return {number}
 */
var jump = function(nums) {
    var idx, far = 0, step = 0, prevFar = -1;
    var nextFar, i;
    while (far < nums.length - 1) {
        step += 1;
        nextFar = far + 1;
        for (i = prevFar + 1; i <= far; i++) {
            nextFar = Math.max(nextFar, i + nums[i]);
        }
        prevFar = far;
        far = nextFar;
    }
    return step;
};