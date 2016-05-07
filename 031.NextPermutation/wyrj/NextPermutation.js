/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var swap = function(arr, i, j) {
    var temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
var reverse = function(arr, start, end) {
    start = start || 0;
    end = end || arr.length - 1;
    while(start < end) {
        swap(arr, start, end);
        start += 1;
        end -= 1;
    }
}
var nextPermutation = function(nums) {
    var len = nums.length;
    var i, j;
    for (i = len - 1; i > 0; i--) {
        if (nums[i] > nums[i - 1]) {
            for (j = len - 1; j >= i; j--) {
                if (nums[j] > nums[i - 1]) {
                    swap(nums, i - 1, j);
                    reverse(nums, i);
                    return;
                }
            }
        }
    }
    reverse(nums);
};