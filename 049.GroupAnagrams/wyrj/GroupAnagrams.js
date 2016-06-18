/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function(strs) {
    var result = [], catN = [], catS = {};
    var sorted, len;
    strs.forEach(function(str) {
        sorted = str.split('').sort().join('');
        len = str.length;
        if (!catN[len]) {
            catN[len] = [sorted];
            catS[sorted] = [str];
        } else {
            for (i = 0; i < catN[len].length; i++) {
                if (catN[len][i] === sorted) {
                    catS[sorted].push(str);
                    break;
                }
            }
            if (i === catN[len].length) {
                catN[len].push(sorted);
                catS[sorted] = [str];
            }
        }
    });
    for (var arr in catS) {
        if (catS[arr]) {
            result.push(catS[arr]);
        }
    }
    return result;
};