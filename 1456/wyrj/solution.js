/**
 * @param {string} s
 * @param {number} k
 * @return {number}
 */
var maxVowels = function(s, k) {
  const vowel = ['a', 'e', 'i', 'o', 'u'];

  let local = 0;
  for (const c of s.slice(0, k)) {
    if (vowel.includes(c)) {
      local += 1;
    }
  }
  let max = local;

  for (let i = k; i < s.length; i++) {
    if (vowel.includes(s.charAt(i - k))) {
      local -= 1;
    }
    if (vowel.includes(s.charAt(i))) {
      local += 1;
    }
    max = Math.max(max, local);
  }
  return max;
};

console.log(maxVowels('tryhard', 4));
