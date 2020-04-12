/**
 * @param {string} s
 ** @param {string[]} wordDict
 ** @return {string[]}
 **/
var wordBreak = function(s, wordDict) {
	const result = new Array(s.length).fill(null);
	const getValue = (index) => {
		if (result[index] !== null) {
			return result[index];
		}
		const arr = [];
		const sub = s.slice(index);
		for (let word of wordDict) {
			if (sub.startsWith(word)) {
				if (sub === word) {
					arr.push([word]);
					continue;
				}
				const can = getValue(index + word.length);
				if (can.length > 0) {
					for (let candidate of can) {
						arr.push([word, ...candidate]);
					}
				}
			}
		}
		return result[index] = arr;
	};
	return getValue(0).map(a => a.join(' '));
};

console.log(wordBreak('catsanddog', ["cat", "cats", "and", "sand", "dog"]));
console.log(wordBreak('pineapplepenapple', ["apple", "pen", "applepen", "pine", "pineapple"]));
console.log(wordBreak("catsanddog", ["cat","cats","and","sand","dog"]));
