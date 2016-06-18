/**
 * @param {number} n
 * @return {number}
 */
var totalNQueens = function(n) {
    var result = 0;
    var rowRecord = [], colRecord = [], slashRecord = [], backslashRecord = [];
    var setRecord = function(r, c, value) {
        rowRecord[r] = value;
        colRecord[c] = value;
        slashRecord[r + c] = value;
        backslashRecord[r + (n - c - 1)] = value;
    };
    var recurrsive = function(r, c, queenNumber) {
        if (r === n) {
            if (queenNumber === n) {
                result += 1;
            }
            return;
        }
        if (!(rowRecord[r] || colRecord[c] || slashRecord[r + c] || backslashRecord[r + (n - c - 1)])) {
            setRecord(r, c, true);
            recurrsive(r + Math.floor((c + 1) / n), (c + 1) % n, queenNumber + 1);
            setRecord(r, c, false);
        }
        recurrsive(r + Math.floor((c + 1) / n), (c + 1) % n, queenNumber);
    };
    recurrsive(0, 0, 0);
    return result;
};