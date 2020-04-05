/**
 ** @param {number[]} nums
 ** @return {number}
 **/
var singleNumber = function(nums) {
	return nums.reduce((v, n) => {
		return v ^ n;
	}, 0);
};
