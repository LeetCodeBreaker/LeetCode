/**
 * @param {number[]} nums
 * @return {number[][]}
 */
var permuteUnique = function(nums) {
    var max = [], uniq = [], result = [];
    var recurrsive = function(arr, index) {
        if (index === nums.length) {
            result.push(arr.slice(0));
            return;
        }
        var i;
        for (i = 0; i < uniq.length; i++) {
            if (!max[i]) {
                continue;
            }
            max[i] -= 1;
            arr[index] = uniq[i];
            recurrsive(arr, index + 1);
            max[i] += 1;
        }
    }
    var j, n, last = -1;
    nums.sort(function(l, r) {
        return l - r;
    });
    for (j = 0; j < nums.length; j++) {
        n = nums[j];
        if (uniq[last] === n) {
            max[last] += 1;
        } else {
            last += 1;
            uniq[last] = n;
            max[last] = 1;
        }
    }
    recurrsive([], 0);
    return result;
};