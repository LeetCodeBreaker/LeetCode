/**
 * @param {number[]} nums
 * @param {number} k
 * @return {boolean}
 */
var kLengthApart = function(nums, k) {
  let lastBit = nums.indexOf(1);
  let space = nums.length;
  for (let i = lastBit + 1; i < nums.length; i++) {
    if (nums[i] === 0) {
      continue;
    }
    space = Math.min(space, i - lastBit - 1)
    lastBit = i;
  }
  return space >= k;
};

console.log(kLengthApart([1,0,0,0,1,0,0,1], 2));
