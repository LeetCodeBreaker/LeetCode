/**
 * @param {number[]} nums
 * @return {number}
 */
var maxProduct = function(nums) {
  if (nums.length === 0) {
    return 0;
  } else if (nums.length === 1) {
    return nums[0];
  }
  const zeroIndex = nums.findIndex(v => v === 0);
  if (zeroIndex >= 0) {
    return Math.max(0, maxProduct(nums.slice(0, zeroIndex)), maxProduct(nums.slice(zeroIndex + 1)));
  }

  const prod = (arr) => {
    return arr.reduce((p, v) => {
      return p * v;
    }, 1);
  };
  const negCount = nums.filter(v => v < 0).length;
  if (negCount % 2 === 0) {
    return prod(nums);
  } else if (negCount === 1) {
    const index = nums.findIndex(v => v < 0);
    return Math.max(prod(nums.slice(0, index)), prod(nums.slice(index + 1)));
  }

  const firstIndex = nums.findIndex(v => v < 0);
  const lastIndex = nums.length - nums.slice().reverse().findIndex(v => v < 0) - 1;

  const firstPart = prod(nums.slice(0, firstIndex + 1));
  const lastPart = prod(nums.slice(lastIndex));
  const midPart = prod(nums.slice(firstIndex + 1, lastIndex));
  return Math.max(firstPart * midPart, midPart * lastPart);
};

console.log(maxProduct([2, 3, -2, 4]));
console.log(maxProduct([-2, 0, -1]));
console.log(maxProduct([-2, 0]));
console.log(maxProduct([-4, -3, -2]));
console.log(maxProduct([3, -1, 4]));
