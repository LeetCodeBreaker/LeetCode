/**
 ** @param {number[]} ratings
 ** @return {number}
 **/
var candy = function(ratings) {
	const arr = ratings.map((r, index) => {
		return {
			val: r,
			index,
		};
	})
	arr.sort((lhs, rhs) => {
		return lhs.val - rhs.val;
	});
	const len = ratings.length;
	const given = new Array(len).fill(1);
	let sum = len;
	for (let {val, index} of arr) {
		if (index > 0 && ratings[index] < ratings[index - 1]) {
			const diff = Math.max(0, given[index] + 1 - given[index - 1]);
			given[index - 1] += diff;
			sum += diff;
		}
		if (index < len - 1 && ratings[index] < ratings[index + 1]) {
			const diff = Math.max(0, given[index] + 1 - given[index + 1]);
			given[index + 1] += diff;
			sum += diff;
		}
	}
	return sum;
};
