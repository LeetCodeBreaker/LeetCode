/**
 * @param {number[]} nums
 * @return {number}
 */
var maxSubArray = function(nums) {
    var dp = [nums[0]];
    var max = dp[0];
    var i;
    for (i = 1; i < nums.length; i++) {
        dp[i] = nums[i] + Math.max(dp[i - 1], 0);
        max = Math.max(max, dp[i]);
    }
    return max;
};