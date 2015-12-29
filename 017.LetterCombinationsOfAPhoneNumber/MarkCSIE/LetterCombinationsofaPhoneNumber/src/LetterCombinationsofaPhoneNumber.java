
import java.util.ArrayList;
import java.util.List;

public class LetterCombinationsofaPhoneNumber {

    public static void main(String[] args) {
        LetterCombinationsofaPhoneNumber test = new LetterCombinationsofaPhoneNumber();
        List<String> testAnswer1 = test.letterCombinations("23");
        System.out.println(testAnswer1);
    }

    public List<String> letterCombinations(String digits) {
        List<String> newCombinations = new ArrayList<>();
        for (int i = 0; i < digits.length(); i++) {
            char[] charArray = null;
            switch (digits.charAt(i)) {
                case '2':
                    charArray = "abc".toCharArray();
                    break;
                case '3':
                    charArray = "def".toCharArray();
                    break;
                case '4':
                    charArray = "ghi".toCharArray();
                    break;
                case '5':
                    charArray = "jkl".toCharArray();
                    break;
                case '6':
                    charArray = "mno".toCharArray();
                    break;
                case '7':
                    charArray = "pqrs".toCharArray();
                    break;
                case '8':
                    charArray = "tuv".toCharArray();
                    break;
                case '9':
                    charArray = "wxyz".toCharArray();
                    break;
                default:
                    System.out.println("WTF");
            }
            List<String> prevCombinations = new ArrayList<>(newCombinations);
            newCombinations.clear();
            for (int j = 0; j < charArray.length; j++) {
                char c = charArray[j];
                if (i == 0) {
                    newCombinations.add(Character.toString(c));
                } else {
                    for (String combination : prevCombinations) {
                        newCombinations.add(combination + c);
                    }
                }
            }
        }
        return newCombinations;
    }
}
