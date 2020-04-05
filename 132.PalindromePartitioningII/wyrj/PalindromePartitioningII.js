/**
 ** @param {string} s
 ** @return {number}
 **/
var minCut = function(s) {
	const len = s.length;
	const table = new Array(len).fill(null).map(() => new Array(len));
	const palindromeTable = new Array(len).fill(null).map(() => new Array(len).fill(null));

	const isPalindrome = (start, end) => {
		if (palindromeTable[start][end] !== null) {
			return palindromeTable[start][end];
		}
		return palindromeTable[start][end] = s[start] === s[end] && (end - start <= 1 || isPalindrome(start + 1, end - 1));
	};

	const resolve = (start, end) => {
		if (table[start][end]) {
			return table[start][end];
		}
		if (isPalindrome(start, end)) {
			return table[start][end] = 1;
		}
		let min = end - start + 1;
		for (let i = start + 1; i <= end; i++) {
			if (isPalindrome(i, end)) {
				min = Math.min(min, resolve(start, i - 1) + 1);
			}
		}
		return table[start][end] = min;
	};

	return resolve(0, len - 1) - 1;
};
