/**
 * @param {number[]} nums
 * @return {number}
 */
var rob = function(nums) {
  if (!nums.length) {
    return 0;
  }
  const table = new Array(nums.length).fill(0);
  for (let i = 0; i < nums.length; i++) {
    table[i] = Math.max((table[i - 2] || 0) + nums[i], table[i - 1] || 0);
  }
  return table[nums.length - 1];
};

console.log(rob([1,2,3,1]));
console.log(rob([2,7,9,3,1]));
