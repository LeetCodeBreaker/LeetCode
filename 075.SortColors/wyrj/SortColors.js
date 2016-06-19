/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var sortColors = function(nums) {
    var left = 0, right = nums.length - 1;
    var swap = function(a, b) {
        var temp = nums[a];
        nums[a] = nums[b];
        nums[b] = temp;
    }
    while(left < right) {
        if (0 !== nums[left] && 0 === nums[right]) {
            swap(left, right);
            left += 1;
            right -= 1;
        } else {
            if (0 === nums[left]) {
                left += 1;
            }
            if (0 !== nums[right]) {
                right -= 1;
            }
        }
    }
    right = nums.length - 1;
    while(left < right) {
        if (2 === nums[left] && 2 !== nums[right]) {
            swap(left, right);
            left += 1;
            right -= 1;
        } else {
            if (2 !== nums[left]) {
                left += 1;
            }
            if (2 === nums[right]) {
                right -= 1;
            }
        }
    }
};