
import java.util.HashMap;

public class FractionToRecurringDecimal {

    public static void main(String[] args) {
        FractionToRecurringDecimal test = new FractionToRecurringDecimal();
        System.out.println(test.fractionToDecimal(22, 3));
    }

    public String fractionToDecimal(int numerator, int denominator) {
        String answer = "";
        if ((long) numerator * (long) denominator < 0) {
            answer += "-";
        }

        long longNumerator = Math.abs((long) numerator);
        long longDenominator = Math.abs((long) denominator);

        Long quotient = longNumerator / longDenominator;
        longNumerator = (longNumerator % longDenominator) * 10;
        answer += Long.toString(quotient);
        if (longNumerator != 0) {
            answer += ".";
        }

        HashMap<Long, HashMap<Long, Integer>> quotientMap = new HashMap<>();
        while (longNumerator != 0) {
            quotient = longNumerator / longDenominator;
            longNumerator = (longNumerator % longDenominator) * 10;
            if (quotientMap.get(quotient) != null && quotientMap.get(quotient).get(longNumerator) != null) {
                int repeatingIndex = quotientMap.get(quotient).get(longNumerator);
                answer += ")";
                answer = new StringBuilder(answer).insert(repeatingIndex, "(").toString();
                break;
            }
            answer += Long.toString(quotient);

            if (quotientMap.get(quotient) == null) {
                HashMap<Long, Integer> map = new HashMap<>();
                quotientMap.put(quotient, map);
            }
            quotientMap.get(quotient).put(longNumerator, answer.length() - 1);
        }
        return answer;
    }
}
