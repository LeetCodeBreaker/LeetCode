/**
 ** @param {number[]} nums
 ** @return {number}
 **/
var longestConsecutive = function(nums) {
	const set = new Set(nums);

	let largest = 0;
	for (let n of nums) {
		if (!set.has(n)) {
			continue;
		}
		set.delete(n);
		let low = n - 1;
		let high = n + 1;
		while (set.has(low)) {
			set.delete(low);
			low -= 1;
		}
		while (set.has(high)) {
			set.delete(high);
			high += 1;
		}
		largest = Math.max(largest, high - low - 1);
	}
	return largest;
};
