/**
 * @param {number[]} nums
 * @param {number} limit
 * @return {number}
 */
var longestSubarray = function(nums, limit) {
  const minQ = [nums[0]], maxQ = [nums[0]];
  let i = 0, j = 0, max = 0;
  const push = (n) => {
    if (n === undefined) {
      return;
    }
    while (maxQ.length > 0 && n > maxQ[maxQ.length - 1]) {
      maxQ.pop();
    }
    maxQ.push(n);
    while (minQ.length > 0 && n < minQ[minQ.length - 1]) {
      minQ.pop();
    }
    minQ.push(n);
  };
  const shift = (n) => {
    if (n === maxQ[0]) {
      maxQ.shift();
    }
    if (n === minQ[0]) {
      minQ.shift();
    }
  };
  while (j < nums.length) {
    const diff = maxQ[0] - minQ[0];
    if (diff > limit) {
      shift(nums[i]);
      i += 1;
    } else {
      max = Math.max(j - i + 1, max);
      j += 1;
      push(nums[j]);
    }
  }
  return max;
};

console.log(longestSubarray([8, 2, 4, 7], 4));
console.log(longestSubarray([4,2,2,2,4,4,2,2], 0));
