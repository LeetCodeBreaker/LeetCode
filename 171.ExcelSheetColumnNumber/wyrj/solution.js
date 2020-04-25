/**
 * @param {string} s
 * @return {number}
 */
var titleToNumber = function(s) {
  const map = {};
  for (let i = 0; i < 26; i++) {
    map[String.fromCharCode(i + 65)] = i + 1;
  }
  let col = 0;
  for (const c of s) {
    col = col * 26 + map[c];
  }
  return col;
};

console.log(titleToNumber('AA'));
console.log(titleToNumber('AAA'), 27*26+1);
