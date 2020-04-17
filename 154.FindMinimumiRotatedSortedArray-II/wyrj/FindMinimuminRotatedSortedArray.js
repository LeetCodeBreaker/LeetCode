/**
 * @param {number[]} nums
 * @return {number}
 */
var findMin = function(nums) {
  let low = 0, high = nums.length;

  trimLow = () => {
    while (low !== high - 1 && nums[low] === nums[low + 1]) {
      low += 1;
    }
  };
  trimHigh = () => {
    while (high !== low + 1 && nums[high - 1] === nums[high - 2]) {
      high -= 1;
    }
  };
  trimLow();
  trimHigh();

  while (low < high) {
    const mid = Math.floor((low + high) / 2);
    const v = nums[mid];
    if ((mid === 0 || v < nums[mid - 1])) {
      return v;
    } else if (nums[high - 1] < v) {
      low = mid + 1;
      trimLow();
    } else {
      high = mid;
      trimHigh();
    }
  }
  return nums[low];
};

console.log(findMin([3, 4, 5, 0, 1, 2]));
console.log(findMin([4, 5, 6, 7, 0, 1, 2]));
console.log(findMin([40, 50, 60, 70, 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10]));
console.log(findMin([1, 3, 5, 0]));
console.log(findMin([3, 3, 3, 0, 1]));
console.log(findMin([3, 3, 3, 0, 1, 2, 2, 2, 2]));
console.log(findMin([3, 0, 0]));
