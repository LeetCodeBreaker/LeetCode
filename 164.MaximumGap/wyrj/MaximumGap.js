/**
 * @param {number[]} nums
 * @return {number}
 */
var maximumGap = function(nums) {
  const maxV = Math.max(...nums);
  const digit = `${maxV}`.length;

  let sorted = nums.slice();
  for (let i = 0; i < digit; i++) {
    const bucket = new Array(10).fill(null).map(() => []);
    const pow = Math.pow(10, i);
    for (n of sorted) {
      bucket[Math.floor(n / pow) % 10].push(n);
    }
    sorted = bucket.reduce((arr, b) => {
      return [...arr, ...b];
    }, []);
  }

  let max = 0;
  for (let i = 0; i < nums.length - 1; i++) {
    max = Math.max(max, sorted[i + 1] - sorted[i]);
  }
  return max;
};

console.log(maximumGap([3,6,9,1]));
