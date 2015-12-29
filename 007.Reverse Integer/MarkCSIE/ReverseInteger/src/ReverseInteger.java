
import java.util.ArrayList;
import java.util.List;


public class ReverseInteger {

    public static void main(String[] args) {
        ReverseInteger test = new ReverseInteger();
        int testAnswer = test.reverse(123);
        System.out.println(testAnswer);
    }
    
    public int reverse(int x) {
        List<Integer> listOfInts = new ArrayList<>();
        int absX = Math.abs(x);
        while (absX > 0) {
            listOfInts.add(absX % 10);
            absX /= 10;
        }

        int answer = 0;
        for (int i = 0; i < listOfInts.size(); i++) {
            answer += listOfInts.get(i) * Math.pow(10, listOfInts.size() - i - 1);
        }
        if (answer == Integer.MAX_VALUE) {
            answer = 0;
        }
        if (x < 0) {
            answer = -answer;
        }
        return answer;
    }
}
