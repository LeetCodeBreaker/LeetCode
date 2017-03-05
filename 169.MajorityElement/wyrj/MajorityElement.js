/**
 * @param {number[]} nums
 * @return {number}
 */
var majorityElement = function(nums) {
    var ans, count = 0;
    nums.forEach(function(n) {
        if (count === 0) {
            ans = n;
        }
        if (ans === n) {
            count++;
        } else {
            count--;
        }
    });
    return ans;
};