var bSearch = function(arr, target, blLeft) {
    var left = 0;
    var right = arr.length - 1;
    var mid;
    while (left <= right) {
        if (left === right) {
            return left;
        }
        mid = (left + right) / 2;
        mid = (blLeft) ? Math.floor(mid) : Math.ceil(mid);
        if (arr[mid] > target) {
            right = mid - ((blLeft) ? 0 : 1);
        } else if (arr[mid] < target) {
            left = mid + ((blLeft) ? 1 : 0);
        } else {
            if (blLeft) {
                right = mid;
            } else {
                left = mid;
            }
        }
    }
}
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var searchRange = function(nums, target) {
    var result = [];
    result.push(bSearch(nums, target, true));
    if (nums[result[0]] !== target) {
        return [-1, -1];
    }
    result.push(bSearch(nums, target, false));
    return result;
};