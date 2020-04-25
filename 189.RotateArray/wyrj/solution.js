/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
var rotate = function(nums, k) {
  const f = (index, n) => {
    const swapSize = nums.length - index;
    if (n === 0) {
      return;
    }
    if (n >= swapSize) {
      f(index, n % swapSize);
      return;
    }
    for (let i = 0; i < n; i++) {
      const temp = nums[index + i];
      nums[index + i] = nums[nums.length - n + i];
      nums[nums.length - n + i] = temp;
    }

    if (n < swapSize / 2) {
      f(index + n, n);
    } else {
      f(index + n, n % (swapSize - n));
    }
  };
  f(0, k);
};

rotate([1,2,3,4,5,6,7], 1);
rotate([1,2,3,4,5,6,7], 2);
rotate([1,2,3,4,5,6,7], 3);
rotate([1,2,3,4,5,6,7], 4);
rotate([1], 1);
rotate([1], 2);
rotate([1, 3], 3);
