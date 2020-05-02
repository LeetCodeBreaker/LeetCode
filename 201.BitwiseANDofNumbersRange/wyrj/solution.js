/**
 * @param {number} m
 * @param {number} n
 * @return {number}
 */
var rangeBitwiseAnd = function(m, n) {
  if (m === n) {
    return m;
  }
  const k = n - m + 1;
  const t = Math.floor(Math.log2(k - 1)) + 1;
  return rangeBitwiseAnd(m >> t, n >> t) << t;
};

console.log(rangeBitwiseAnd(5, 7));
console.log(rangeBitwiseAnd(0, 1));
console.log(rangeBitwiseAnd(1, 2));
console.log(rangeBitwiseAnd(3, 4));
