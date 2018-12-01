/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    const rLen = board.length;
    const cLen = board[0].length;
    const checkLetter = (r, c, index) => {
        const letter = word.charAt(index);
        if (board[r][c] === letter) {
            board[r][c] = false;
            if (dfs(r, c, index + 1)) {
                return true;
            }
            board[r][c] = letter;
        }
        return false;
    }
    const dfs = (r, c, index) => {
        if (index === word.length) {
            return true;
        }
        return (r > 0 && checkLetter(r - 1, c, index)) ||
            (r < rLen - 1 && checkLetter(r + 1, c, index)) ||
            (c > 0 && checkLetter(r, c - 1, index)) ||
            (c < cLen - 1 && checkLetter(r, c + 1, index));
    }
    return board.some((arr, r) => {
        return arr.some((ch, c) => {
            return checkLetter(r, c, 0);
        });
    });
};
