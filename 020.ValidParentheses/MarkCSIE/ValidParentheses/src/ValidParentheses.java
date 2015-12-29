
import java.util.ArrayDeque;
import java.util.Deque;

public class ValidParentheses {

    public static void main(String[] args) {
        ValidParentheses test = new ValidParentheses();
        System.out.println(test.isValid("()[]{}"));
    }

    public boolean isValid(String s) {
        if (s.length() % 2 != 0) {
            return false;
        }

        Deque<Character> parenthesisStack = new ArrayDeque<>();
        for (char c : s.toCharArray()) {
            switch (c) {
                case '(':
                    parenthesisStack.push(')');
                    break;
                case '[':
                    parenthesisStack.push(']');
                    break;
                case '{':
                    parenthesisStack.push('}');
                    break;
                case ')':
                    if (parenthesisStack.isEmpty() || parenthesisStack.pop() != ')') {
                        return false;
                    }
                    break;
                case ']':
                    if (parenthesisStack.isEmpty() || parenthesisStack.pop() != ']') {
                        return false;
                    }
                    break;
                case '}':
                    if (parenthesisStack.isEmpty() || parenthesisStack.pop() != '}') {
                        return false;
                    }
                    break;
                default:
                    return false;
            }
        }
        return parenthesisStack.isEmpty();
    }
}
