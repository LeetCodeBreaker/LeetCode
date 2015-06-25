/* 160ms */
/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var sorted = nums.slice(0).sort(cmp);
    var i = 0, j = nums.length - 1;
    while(i < j) {
        if (target === (sorted[i] + sorted[j])) {
            var first = nums.indexOf(sorted[i]) + 1;
            var second = nums.lastIndexOf(sorted[j]) + 1;
            return [Math.min(first, second), Math.max(first, second)];
        }
        if (target > (sorted[i] + sorted[j])) {
            i++;
        } else if (target < (sorted[i] + sorted[j])) {
            j--;
        }
    }
};

function cmp(a,b) {
    return a-b;
}