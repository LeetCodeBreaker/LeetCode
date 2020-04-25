/**
 * @param {number} n
 * @return {number}
 */
var trailingZeroes = function(n) {
  let result = 0;
  while (n >= 5) {
    n = Math.floor(n / 5);
    result += n;
  }
  return result;
};

console.log(trailingZeroes(13));
console.log(trailingZeroes(25));
console.log(trailingZeroes(125));
