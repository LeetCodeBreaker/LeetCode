/**
 * @param {number} rowIndex
 * @return {number[]}
 */
var getRow = function(rowIndex) {
    const result = new Array(rowIndex + 1);
    for (let i = 0; i <= rowIndex; i++) {
        result[i] = 1;
        for (let j = i - 1; j > 0; j--) {
            result[j] += result[j - 1];
        }
    }
    return result;
};
