/**
 * @param {number} n
 * @return {string}
 */
var countAndSay = function(n) {
    var result = '1';
    var i, j, k, prev, count, nextResult;
    for (i = 1; i < n; i++) {
        prev = null;
        count = 0;
        nextResult = '';
        for (j = 0; j < result.length; j++) {
            if (null !== prev && result[j] !== prev) {
                nextResult = nextResult + count + prev;
                count = 1;
            } else {
                count += 1;
            }
            prev = result[j];
        }
        nextResult = nextResult + count + prev;
        result = nextResult;
    }
    return result;
};