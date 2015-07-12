/* 228ms */
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
var fourSum = function(nums, target) {
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
    var i, j, k, l, ret = [];
    for (i = 0; i < nums.length - 3; i++) {
        if (i !== 0 && nums[i] === nums[i-1]) {
            continue;
        }
        for (j = i + 1; j < nums.length - 2; j++) {
            if (j !== i + 1 && nums[j] === nums[j - 1]) {
                continue;
            }
            k = j + 1;
            l = nums.length - 1;
            for (k = j + 1; k < l; k++){
                if (k !== j + 1 && nums[k] === nums[k - 1]) {
                    continue;
                }
                while (nums[i] + nums[j] + nums[k] + nums[l] > target && l > k + 1) {
                    l--;
                }
                if (nums[i] + nums[j] + nums[k] + nums[l] === target) {
                    ret.push([nums[i], nums[j], nums[k], nums[l]]);
                    l--;
                }
            }
        }
    }
    return ret;
};