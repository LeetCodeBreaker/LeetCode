/**
 ** @param {character[][]} board
 ** @return {void} Do not return anything, modify board in-place instead.
 **/
var solve = function(board) {
	const rowLength = board.length;
	const colLength = board[0] ? board[0].length : 0;
	const f = (x, y) => {
		if (x < 0 || x >= rowLength || y < 0 || y >= colLength || board[x][y] !== 'O') {
			return;
		}
		board[x][y] = 'V';
		f(x - 1, y);
		f(x + 1, y);
		f(x, y - 1);
		f(x, y + 1);
	}
	for (let i = 0; i < rowLength; i++) {
		f(i, 0);
		f(i, colLength - 1);
	}
	for (let i = 0; i < colLength; i++) {
		f(0, i);
		f(rowLength - 1, i);
	}
	for (let i = 0; i < rowLength; i++) {
		for (let j = 0; j < colLength; j++) {
			board[i][j] = board[i][j] === 'V' ? 'O' : 'X';
		}
	}
};
