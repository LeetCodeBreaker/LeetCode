
import java.util.ArrayList;
import java.util.List;

public class SpiralMatrix {

    public static void main(String[] args) {
        SpiralMatrix test = new SpiralMatrix();
        int[][] testCase1 = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},};
        System.out.println(test.spiralOrder(testCase1));
    }

    public List<Integer> spiralOrder(int[][] matrix) {
        List<Integer> answer = new ArrayList<>();
        if (matrix.length == 0) {
            return answer;
        }
        int vertical = matrix.length;
        int horizontal = matrix[0].length;

        int i = 0;
        int j = -1;

        int leftRight = 1;
        int upDown = 1;
        int totalLength = matrix[0].length * matrix.length;
        while (answer.size() < totalLength) {
            for (int count = 0; count < horizontal; count++) {
                j += leftRight;
                answer.add(matrix[i][j]);
            }
            leftRight *= -1;
            vertical--;

            for (int count = 0; count < vertical; count++) {
                i += upDown;
                answer.add(matrix[i][j]);
            }
            upDown *= -1;
            horizontal--;
        }
        return answer;
    }
}
