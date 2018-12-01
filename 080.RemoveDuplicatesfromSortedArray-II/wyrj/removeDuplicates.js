/**
 * @param {number[]} nums
 * @return {number}
 */
var removeDuplicates = function(nums) {
    let newLen = 2;
    if (nums.length < newLen) return nums.length;
    let skip = nums[0] === nums[1];
    for (let i = 2, len = nums.length; i < len; i++) {
        if (nums[i] !== nums[i - 1]) {
            nums[newLen] = nums[i];
            newLen += 1;
            skip = false;
        } else if (!skip) {
            nums[newLen] = nums[i];
            newLen += 1;
            skip = true;
        }
    }
    return newLen;
};
