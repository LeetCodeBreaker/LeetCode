/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
  let low = 0, high = nums.length;

  while (low < high) {
    const mid = Math.floor((low + high) / 2);
    const v = nums[mid];
    if ((mid === 0 || v < nums[mid - 1]) && (mid === nums.length - 1 || v < nums[mid + 1])) {
      return v;
    } else if (nums[high - 1] < v) {
      low = mid + 1;
    } else {
      high = mid;
    }
  }
  return nums[low];
};

console.log(findMin([3, 4, 5, 1, 2]));
console.log(findMin([4, 5, 6, 7, 0, 1, 2]));
console.log(findMin([40, 50, 60, 70, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]));
