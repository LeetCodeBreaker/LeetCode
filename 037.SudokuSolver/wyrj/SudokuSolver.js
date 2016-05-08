class SudokuSolver {
    constructor(board) {
        this.board = board;
        this.rowRecord = [];
        this.colRecord = [];
        this.groupRecord = [];
        this.init();
    }
    
    init() {
        var i, j;
        for (i = 0; i < 9; i++) {
            this.rowRecord[i] = [];
            this.colRecord[i] = [];
            this.groupRecord[i] = [];
        }
        for (i = 0; i < 9; i++) {
            for (j = 0; j < 9; j++) {
                if ('.' !== this.board[i][j]) {
                    this.setRecord(i, j, this.board[i][j], true);
                }
            }
        }
    }
    
    setRecord(row, col, value, flag) {
        this.rowRecord[row][value] = flag;
        this.colRecord[col][value] = flag;
        this.groupRecord[this.translateGroupIndex(row, col)][value] = flag;
    }
    
    checkRecord(row, col, value) {
        return (this.rowRecord[row][value] || this.colRecord[col][value]
            || this.groupRecord[this.translateGroupIndex(row, col)][value]);
    }
    
    translateGroupIndex(row, col) {
        return Math.floor(row / 3) * 3 + Math.floor(col / 3);
    }
    
    solve() {
        return this.recusiveSolve(0, 0);
    }
    
    recusiveSolve(row, col) {
        var n;
        if (9 <= row) {
            return true;
        }
        if ('.' !== this.board[row][col]) {
            return this.recusiveSolve(row + Math.floor((col + 1) / 9), (col + 1) % 9);
        }
        for (n = 1; n <= 9; n++) {
            if (this.checkRecord(row, col, n)) {
                continue;
            }
            this.setRecord(row, col, n, true);
            this.board[row][col] = n;
            if (this.recusiveSolve(row + Math.floor((col + 1) / 9), (col + 1) % 9)) {
                return true;
            }
            this.setRecord(row, col, n, false);
        }
        this.board[row][col] = '.';
        return false;
    }
}
/**
 * @param {character[][]} board
 * @return {void} Do not return anything, modify board in-place instead.
 */
var solveSudoku = function(board) {
    var solver = new SudokuSolver(board);
    solver.solve();
    return;
};