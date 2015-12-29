
public class SudokuSolver {

    private char[][] answerBoard;

    public static void main(String[] args) {

        char[][] board1 = {
            {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'}

        };
        SudokuSolver test = new SudokuSolver();
        test.printBoard(board1);
        test.solveSudoku(board1);
        test.printBoard(board1);
    }

    private void printBoard(char[][] board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                System.out.print(board[i][j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public void solveSudoku(char[][] board) {
        solve(board, 0, 0);
        // Copy board
        for (int i = 0; i < this.answerBoard.length; i++) {
            System.arraycopy(this.answerBoard[i], 0, board[i], 0, this.answerBoard[0].length);
        }
        //
    }

    private void solve(char[][] board, int i, int j) {
        while (true) {
            if (board[i][j] == '.') {
                for (int k = 1; k < 10; k++) {
                    char number = Character.forDigit(k, 10);
                    if (checkCross(board, number, i, j) && checkSquare(board, number, i, j)) {
                        // Copy board
                        char[][] tempBoard = new char[9][9];
                        for (int l = 0; l < board.length; l++) {
                            System.arraycopy(board[l], 0, tempBoard[l], 0, board[0].length);
                        }
                        //

                        tempBoard[i][j] = number;
                        solve(tempBoard, i, j);
                    }
                }
                break;
            } else if (++j == 9) {
                j = 0;
                if (++i == 9) {
                    this.answerBoard = board;
                    break;
                }
            }
        }
    }

    private boolean checkCross(char[][] board, char number, int i, int j) {
        // Horizontal
        for (int y = 0; y < 9; y++) {
            if (number == board[i][y] && y != j) {
                return false;
            }
        }

        // Vertical
        for (int x = 0; x < 9; x++) {
            if (number == board[x][j] && x != i) {
                return false;
            }
        }
        return true;
    }

    private boolean checkSquare(char[][] board, char number, int i, int j) {
        for (int x = 3 * (i / 3); x < 3 * (i / 3) + 3; x++) {
            for (int y = 3 * (j / 3); y < 3 * (j / 3) + 3; y++) {
                if (number == board[x][y] && (x != i || y != j)) {
                    return false;
                }
            }
        }
        return true;
    }

}
