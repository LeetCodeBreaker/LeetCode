/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function(nums, target) {
    var left = 0;
    var right = nums.length - 1;
    var mid;
    while (left <= right) {
        mid = Math.floor((left + right) / 2);
        if (nums.length - 1 === mid && nums[mid] < target) {
            return mid + 1;
        }
        if (nums[mid] >= target && (0 === mid || target > nums[mid - 1])) {
            return mid;
        }
        if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
};