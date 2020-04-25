/**
 * @param {number} n
 * @return {string}
 */
var convertToTitle = function(n) {
  const dict = new Array(26).fill(null).map((_, idx) => String.fromCharCode(idx + 65));
  let result = '';
  while (n > 0) {
    result = dict[(n - 1) % 26] + result;
    n = Math.floor((n - 1) / 26);
  }
  return result;
};

console.log(convertToTitle(26));
console.log(convertToTitle(27));
console.log(convertToTitle(27*26 + 1));
