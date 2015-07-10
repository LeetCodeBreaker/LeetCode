/* 356ms */
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function(s) {
    var translator = [[1000, 'M'], [900, 'CM'],
                    [500, 'D'], [400, 'CD'],
                    [100, 'C'], [90, 'XC'],
                    [50, 'L'], [40, 'XL'], 
                    [10, 'X'], [9, 'IX'], 
                    [5, 'V'], [4, 'IV'], [1, 'I']];
    var ret = 0;
    for (var i = 0; i < translator.length; i++) {
        while(0 === s.indexOf(translator[i][1])) {
            ret += translator[i][0];
            s = s.slice(translator[i][1].length);
        }
    }
    return ret;
};