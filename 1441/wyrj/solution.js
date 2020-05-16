/**
 * @param {number[]} target
 * @param {number} n
 * @return {string[]}
 */
var buildArray = function(target, n) {
  let ni = 0;
  const ans = [];
  for (let i = 1; i <= n && ni < target.length; i++) {
    ans.push('Push');
    if (target[ni] === i) {
      ni += 1;
    } else {
      ans.push('Pop');
    }
  }
  return ans;
};

console.log(buildArray([1,3], 3));
console.log(buildArray([1,2], 3));
