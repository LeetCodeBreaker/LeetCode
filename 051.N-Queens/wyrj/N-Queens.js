/**
 * @param {number} n
 * @return {string[][]}
 */
var solveNQueens = function(n) {
    var board = [];
    var result = [];
    var rowRecord = [], colRecord = [], slashRecord = [], backslashRecord = [];
    var board2str = function(board) {
        var i, j, output = [];
        for (i = 0; i < n; i++) {
            output.push(board[i].join(''));
        }
        return output;
    };
    var setRecord = function(r, c, value) {
        rowRecord[r] = value;
        colRecord[c] = value;
        slashRecord[r + c] = value;
        backslashRecord[r + (n - c - 1)] = value;
    };
    var recurrsive = function(r, c, queenNumber) {
        if (r === n) {
            if (queenNumber === n) {
                result.push(board2str(board));
            }
            return;
        }
        if (!(rowRecord[r] || colRecord[c] || slashRecord[r + c] || backslashRecord[r + (n - c - 1)])) {
            setRecord(r, c, true);
            board[r][c] = 'Q';
            recurrsive(r + Math.floor((c + 1) / n), (c + 1) % n, queenNumber + 1);
            setRecord(r, c, false);
        }
        board[r][c] = '.';
        recurrsive(r + Math.floor((c + 1) / n), (c + 1) % n, queenNumber);
    };
    var i;
    for (i = 0; i < n; i++) {
        board[i] = [];
    }
    recurrsive(0, 0, 0);
    return result;
};