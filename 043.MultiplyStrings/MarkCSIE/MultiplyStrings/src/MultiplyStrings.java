
public class MultiplyStrings {

    public static void main(String[] args) {
        MultiplyStrings test = new MultiplyStrings();
        System.out.println(test.multiply("123", "456"));
    }

    public String multiply(String num1, String num2) {
        if (num1.equals("0") || num2.equals("0")) {
            return "0";
        }

        StringBuilder answer = new StringBuilder();
        int sizeOfCarryList = num1.length() + num2.length();
        int[] carryList = new int[sizeOfCarryList];

        for (int i = num1.length() - 1; i >= 0; i--) {
            int digit1 = Character.getNumericValue(num1.charAt(i));
            for (int j = num2.length() - 1; j >= 0; j--) {
                int digit2 = Character.getNumericValue(num2.charAt(j));
                carryList[i + j + 1] += digit1 * digit2;
            }
        }
        for (int i = sizeOfCarryList - 1; i > 0; i--) {
            carryList[i - 1] += carryList[i] / 10;
            answer.insert(0, carryList[i] % 10);
        }
        if (carryList[0] != 0) {
            answer.insert(0, carryList[0]);
        }
        return answer.toString();
    }
}
