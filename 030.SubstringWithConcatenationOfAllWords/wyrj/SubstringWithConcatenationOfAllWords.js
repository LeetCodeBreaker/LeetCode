/**
 * @param {string} s
 * @param {string[]} words
 * @return {number[]}
 */
var findSubstring = function(s, words) {
    var result = [];
    var unitLen = words[0].length;
    var wordsLen = words.length;
    var strToken = [], wordsStr, matchCount;
    var i, j, index, start;
    var cmpFn = function(lhs, rhs) {
        return (lhs === rhs) ? 0 : (lhs > rhs) ? 1 : -1;
    }
    if (s.length < unitLen * wordsLen) {
        return result;
    }
    wordsStr = words.sort(cmpFn).join('');
    for (i = 0; i < unitLen; i++) {
        strToken = [];
        for (j = i; j < s.length; j += unitLen) {
            strToken.push(s.substr(j, unitLen));
        }
        matchCount = 0;
        for (j = 0; j < strToken.length; j++) {
            index = words.indexOf(strToken[j]);
            if (-1 === index) {
                matchCount = 0;
            } else {
                matchCount += 1;
            }
            if (matchCount === wordsLen) {
                start = j - matchCount + 1;
                if (strToken.slice(start, start + matchCount).sort(cmpFn).join('') === wordsStr) {
                    result.push(start * unitLen + i);
                }
                matchCount -= 1;
            }
        }
    }
    return result;
};