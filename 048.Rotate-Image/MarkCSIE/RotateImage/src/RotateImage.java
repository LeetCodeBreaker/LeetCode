
public class RotateImage {

    public static void main(String[] args) {
        RotateImage test = new RotateImage();
        int[][] testCase1 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},};

        test.printSquare(testCase1);
        test.rotate(testCase1);
        test.printSquare(testCase1);
    }

    private void printSquare(int[][] matrix) {
        for (int[] matrix1 : matrix) {
            for (int j = 0; j < matrix1.length; j++) {
                System.out.print(matrix1[j] + " ");
            }
            System.out.println();
        }
        System.out.println();
    }

    public void rotate(int[][] matrix) {
        int n = matrix.length;
        for (int i = 0; i <= (n - 1) / 2; i++) {
            for (int j = i; j <= (n - 1) - (i + 1); j++) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[(n - 1) - j][i]; // leftUp = leftDown
                matrix[(n - 1) - j][i] = matrix[(n - 1) - i][(n - 1) - j]; // leftDown = rightDown
                matrix[(n - 1) - i][(n - 1) - j] = matrix[j][(n - 1) - i]; // rightDown = rightUp
                matrix[j][(n - 1) - i] = temp; // rightUp = leftUp     
            }
        }
    }

}
