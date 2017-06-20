/* 156ms */
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var threeSumClosest = function(nums, target) {
    var cmp = function(a, b) {
        if (a > b) {
            return 1;
        } else if (a < b) {
            return -1;
        } else {
            return 0;
        }
    };
    nums.sort(cmp);
    var i, j, k, retDiff = 1000000000, ret;
    for (i = 0; i < nums.length - 2; i++) {
        j = i + 1;
        k = nums.length - 1;
        while(j < k) {
            var diff = nums[i] + nums[j] + nums[k] - target;
            if (Math.abs(diff) < retDiff) {
                retDiff = Math.abs(diff);
                ret = nums[i] + nums[j] + nums[k];
            }
            if (diff > 0) {
                k--;
            } else if (diff < 0) {
                j++;
            } else {
                return target;
            }
        }
    }
    return ret;
};