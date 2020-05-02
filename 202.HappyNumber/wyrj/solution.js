/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function(n) {
  if (n === 0) {
    return false;
  }
  const set = new Set();
  while (n !== 1) {
    if (set.has(n)) {
      return false;
    }
    set.add(n);
    n = `${n}`.split('').reduce((sum, v) => {
      v = parseInt(v, 10);
      return sum + v * v;
    }, 0);
  }
  return true;
};

console.log(isHappy(19));
