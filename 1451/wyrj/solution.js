/**
 * @param {string} text
 * @return {string}
 */
var arrangeWords = function(text) {
  const result = text.toLowerCase().split(' ').sort((lhs, rhs) => {
    return lhs.length - rhs.length;
  }).join(' ');
  return result.charAt(0).toUpperCase() + result.slice(1);
};

console.log(arrangeWords('Leetcode is good'));
