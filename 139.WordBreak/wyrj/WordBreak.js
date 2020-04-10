/**
 ** @param {string} s
 ** @param {string[]} wordDict
 ** @return {boolean}
 **/
var wordBreak = function(s, wordDict) {
	const table = new Array(s.length).fill(null); 
	const getValue = (index) => {
		if (table[index] !== null) {
			return table[index];
		}
		const sub = s.slice(index);
		let result = false;
		for (let word of wordDict) {
			if (sub.startsWith(word) && (sub === word || getValue(index + word.length))) {
				result = true;
				break;
			}
		}
		return table[index] = result;
	};
	return getValue(0);
};

console.log(wordBreak('applepenapple', ['apple', 'pen']));
console.log(wordBreak('catsandog', ['cats', 'dog', 'sand', 'and', 'cat']));
console.log(wordBreak.apply(null, (() => {
	return ['a'.repeat(151) + 'b', new Array(5).fill(null).map((v, i) => 'a'.repeat(i + 6))];
})()));
