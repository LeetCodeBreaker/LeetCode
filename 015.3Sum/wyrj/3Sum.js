/* 280ms */
/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function(nums) {
    var cmp = function(a,b) {
        if (a > b) {
            return 1;
        } else if (a < b) {
            return -1;
        } else {
            return 0;
        }
    };
    nums.sort(cmp);
    var ret = [], index, i, j, nonPosIndex, nonNegIndex;
    for (i = 0; i < nums.length; i++) {
        if ((0 > nums[i-1] || 0 === i) && 0 <= nums[i]) {
            nonNegIndex = i;
        }
        if (0 >= nums[i] && (0 < nums[i+1] || nums.length - 1 === i)) {
            nonPosIndex = i;
        }
    }
    if (2 <= nonPosIndex - nonNegIndex) {
        ret.push([0,0,0]);
    }
    for (i = 0; i < nonNegIndex; i++) {
        if (i > 0 && nums[i] === nums[i - 1]) {
            continue;
        }
        index = nums.length - 1;
        for (j = i + 1; j < index; j++) {
            if (j !== i + 1 && nums[j] === nums[j-1]) {
                continue;
            }
            while((0 < nums[index] + nums[i] + nums[j]) && index > j) {
                index--;
            }
            if (j === index) {
                break;
            }
            if (0 === nums[index] + nums[i] + nums[j]) {
                ret.push([nums[i], nums[j], nums[index]]);
                index--;
            }
        }
    }
    return ret;
};