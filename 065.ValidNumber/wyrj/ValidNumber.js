/**
 * @param {string} s
 * @return {boolean}
 */
var isNumber = function(s) {
    if (s.trim().match(/^[+-]?((\d+(\.\d+)?)|((\d+\.)?\d+)|(\d+\.)|(\.\d+))(e[+-]?\d+)?$/)) {
        return true;
    }
    return false;
};