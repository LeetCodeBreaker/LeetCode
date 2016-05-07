/**
 * @param {string} s
 * @return {number}
 */
var longestValidParentheses = function(s) {
    var max = 0;
    var queue = [], localMax = [];
    var i, index, spIndex;
    for (i = 0; i < s.length; i++) {
        if ('(' === s[i]) {
            queue.push(i);
            localMax[i] = 0;
        } else if (0 !== queue.length) {
            index = queue.pop();
            localMax[i] = i - index + 1;
            if (localMax[index - 1]) {
                localMax[i] += localMax[index - 1];
            }
        } else {
            localMax[i] = 0;
        }
        max = Math.max(max, localMax[i]);
    }
    return max;
};