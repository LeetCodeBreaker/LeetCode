/**
 ** @param {number[]} nums
 ** @return {number}
 **/
var singleNumber = function(nums) {
	const bits = new Array(3).fill(0);
	const carry = new Array(3);

	bits[2] = ~0;
	for (let num of nums) {
		carry[1] = num & bits[0];
		carry[2] = num & bits[1];
		carry[0] = num & bits[2];

		bits[0] = bits[0] ^ carry[1] | carry[0];
		bits[1] = bits[1] ^ carry[2] | carry[1];
		bits[2] = bits[2] ^ carry[0] | carry[2];
	}

	return bits[0];
};

// console.log(singleNumber([2, 2, 3, 2]), 3);
console.log(singleNumber([-2,-2,1,1,-3,1,-3,-3,-4,-2]), -4);
