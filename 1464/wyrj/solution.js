/**
 *  * @param {number[]} nums
 *   * @return {number}
 *    */
var maxProduct = function(nums) {
  let max = [0, 0];
  let min = [0, 0];
  for (const _ of nums) {
    const n = _ - 1;
    if (n > 0) {
      if (n > max[1]) {
        max.pop();
        max.push(n);
      }
      if (n > max[0]) {
        max = [n, max[0]];
      }
    } else {
      if (n < min[1]) {
        min.pop();
        min.push(n);
      }
      if (n < min[0]) {
        min = [n, min[0]];
      }
    }
  }
  return Math.max(max[0] * max[1], min[0] * min[1]);
};

console.log(maxProduct([3,4,5,2]));
