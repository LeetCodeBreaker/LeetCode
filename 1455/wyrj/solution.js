/**
 * @param {string} sentence
 * @param {string} searchWord
 * @return {number}
 */
var isPrefixOfWord = function(sentence, searchWord) {
  const index = sentence.split(' ').findIndex((s) => s.startsWith(searchWord));
  return index === -1 ? index : index + 1;
};

console.log(isPrefixOfWord('this problem is an easy problem', 'pro'));
