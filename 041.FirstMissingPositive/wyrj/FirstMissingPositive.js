/**
 * @param {number[]} nums
 * @return {number}
 */
var firstMissingPositive = function(nums) {
    var i = 0, n;
    while (i < nums.length) {
        n = nums[i];
        
        if (n <= 0 || n > nums.length || nums[n - 1] === n) {
            i += 1;
            continue;
        }
        nums[i] = nums[n - 1];
        nums[n - 1] = n;
    }
    for (i = 0; i < nums.length; i++) {
        if (nums[i] !== i + 1) {
            return i + 1;
        }
    }
    return nums.length + 1;
};