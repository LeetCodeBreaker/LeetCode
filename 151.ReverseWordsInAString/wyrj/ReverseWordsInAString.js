/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function(s) {
  return s.split(' ').filter(w => w).reverse().join(' ');
};

console.log(reverseWords('the sky is blue'));
console.log(reverseWords('  hello world! '));
