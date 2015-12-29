
public class ValidSudoku {

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
        ValidSudoku test = new ValidSudoku();
        System.out.println(test.isValidSudoku(board1));
    }

    public boolean isValidSudoku(char[][] board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.') {
                    continue;
                }
                // check horizontal
                for (int k = j + 1; k < 9; k++) {
                    if (board[i][j] == board[i][k]) {
                        return false;
                    }
                }

                // check vertical
                for (int k = i + 1; k < 9; k++) {
                    if (board[i][j] == board[k][j]) {
                        return false;
                    }
                }

                // check square
                for (int x = 3 * (i / 3); x < 3 * (i / 3) + 3; x++) {
                    for (int y = 3 * (j / 3); y < 3 * (j / 3) + 3; y++) {
                        if (board[i][j] == board[x][y] && (x != i || y != j)) {
                            return false;
                        }
                    }
                }

            }
        }
        return true;
    }
}
