
import java.util.ArrayList;
import java.util.List;

public class GenerateParentheses {

    public static void main(String[] args) {
        GenerateParentheses test = new GenerateParentheses();
        test.generateParenthesis(3);
    }

    public List<String> generateParenthesis(int n) {
        List<String> answer = treeTraverse(n, n, "");
        for (String item : answer) {
            System.out.println(item);
        }
        return answer;
    }

    private List<String> treeTraverse(int left, int right, String currentString) {
        List<String> answer = new ArrayList<>();
        if (left == 0 && right == 0) {
            answer.add(currentString);
            return answer;
        }

        if (left > 0) {
            List<String> leftAnswer = treeTraverse(left - 1, right, currentString + "(");
            answer.addAll(leftAnswer);
        }
        if (right > left) {
            List<String> rightAnswer = treeTraverse(left, right - 1, currentString + ")");
            answer.addAll(rightAnswer);
        }

        return answer;
    }
}
