/* 132ms */
/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function(nums, val) {
    var index = 0, len = nums.length;
    while(index < len) {
        if (nums[index] === val) {
            nums[index] = nums[len - 1];
            len--;
        } else {
            index++;
        }
    }
    return len;
};