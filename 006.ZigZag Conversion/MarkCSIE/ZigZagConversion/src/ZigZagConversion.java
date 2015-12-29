
import java.util.ArrayList;
import java.util.List;

public class ZigZagConversion {

    public static void main(String[] args) {
        ZigZagConversion test = new ZigZagConversion();
        String testAnswer = test.convert("PAYPALISHIRING", 3);
        System.out.println(testAnswer);
    }

    public String convert(String s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        String answer = "";

//        for (int i = 0; i < numRows; i++) {
//            int index = i;
//            boolean down = true;
//            while (index < s.length()) {
//                int interval;
//                if (down) {
//                    interval = (numRows - (i + 1)) * 2;
//                    down = false;
//                } else {
//                    interval = i * 2;
//                    down = true;
//                }
//                if (interval != 0) {
//                    answer += s.charAt(index);
//                    index += interval;
//                }
//            }
//        }
        List<String> listOfStrings = new ArrayList<>();
        for (int i = 0; i < numRows; i++) {
            listOfStrings.add("");
        }

        int count = 0;
        boolean up = true;
        for (char ch : s.toCharArray()) {
            listOfStrings.set(count, listOfStrings.get(count) + ch);
            if (up) {
                count++;
                if (count == numRows) {
                    count = numRows - 2;
                    up = false;
                }
            } else {
                count--;
                if (count == -1) {
                    count = 1;
                    up = true;
                }
            }

        }

        for (int i = 0; i < numRows; i++) {
            answer += listOfStrings.get(i);
//            System.out.println(listOfStrings.get(i));
        }
        return answer;
    }
}
