/**
 * @param {number[]} nums
 * @param {number} target
 * @return {boolean}
 */
var search = function(nums, target) {
    let low = 0;
    let high = nums.length - 1;
    while (low <= high) {
        if (nums[low] === target) return true;
        if (nums[low] === nums[high]) {
            high--;
            low++;
            continue;
        }
        const mid = Math.floor((low + high) / 2);
        if (nums[mid] === target) return true;
        if ((nums[low] <= target && target <= nums[mid]) ||
            (nums[low] > nums[mid] && (target > nums[low] || target < nums[mid]))) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return false;
};
