/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var subsetsWithDup = function(nums) {
    const result = [[]];
    nums.sort((l, r) => {
        return l - r;
    });
    let j;
    for (let i = 0; i < nums.length; i++) {
        if (i === 0 || nums[i] !== nums[i - 1]) {
            j = 0;
        }
        const len = result.length;
        while (j < len) {
            const arr = result[j].slice();
            arr.push(nums[i]);
            result.push(arr);
            j++;
        }
    }
    return result;
};
