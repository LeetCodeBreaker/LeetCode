/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function(n) {
  let count = 0;
  while (n > 0) {
    if (n % 2 === 1) {
      count += 1;
    }
    n = Math.floor(n / 2);
  }
  return count;
};

console.log(hammingWeight(32));
