/**
 * @param {number[]} nums
 * @return {boolean}
 */
var canJump = function(nums) {
    var max = 0;
    var i = 0;
    while(i <= max) {
        max = Math.max(i + nums[i], max);
        if (max >= (nums.length - 1)) {
            return true;
        }
        i += 1;
    }
    return false;
};