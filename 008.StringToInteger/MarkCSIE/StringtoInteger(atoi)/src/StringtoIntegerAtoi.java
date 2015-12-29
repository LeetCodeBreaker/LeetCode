
public class StringtoIntegerAtoi {

    public static void main(String[] args) {
        StringtoIntegerAtoi test = new StringtoIntegerAtoi();

        int testAnswer = test.myAtoi("123");
        System.out.println(testAnswer);
    }

    public int myAtoi(String str) {
        long answer = 0;
        boolean signed = false;
        boolean negative = false;
        for (int i = 0; i < str.length(); i++) {
            char c = str.charAt(i);
            int digit = Character.getNumericValue(c);
            if (digit > -1 && digit < 10) {
                answer += Character.getNumericValue(c) * Math.pow(10, str.length() - i - 1);
            } else if (c == '+') {
                if (signed) {
                    answer = 0;
                    break;
                }
                signed = true;
            } else if (c == '-') {
                if (signed) {
                    answer = 0;
                    break;
                }
                signed = true;
                negative = true;
            } else if (c == ' ') {
                if (i != 0 && str.charAt(i - 1) != ' ') {
                    answer /= Math.pow(10, str.length() - i);
                    break;
                }
            } else {
                answer /= Math.pow(10, str.length() - i);
                break;
            }
        }
//        System.out.println(answer);
        if (negative) {
            answer = -answer;
        }
        answer = Math.max(answer, Integer.MIN_VALUE);
        answer = Math.min(answer, Integer.MAX_VALUE);

        return (int) answer;
    }
}
