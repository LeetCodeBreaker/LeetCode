/**
 * @param {number[]} nums
 * @return {number}
 */
var findPeakElement = function(nums) {
  if (nums.length === 1 || nums[0] > nums[1]) {
    return 0;
  }
  if (nums[nums.length - 1] > nums[nums.length - 2]) {
    return nums.length - 1;
  }

  let low = 0, high = nums.length - 1;
  while (low <= high) {
    const mid = Math.floor((low + high) / 2);
    if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) {
      return mid;
    }
    if (nums[mid] < nums[mid - 1]) {
      high = mid - 1;
    } else {
      low = mid + 1;
    }
  }
  return low;
};

console.log(findPeakElement([1,2,3,1]));
console.log(findPeakElement([1,2,1,3,5,6,4]));
