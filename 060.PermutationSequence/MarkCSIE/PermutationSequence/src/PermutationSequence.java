
import java.util.ArrayList;
import java.util.List;

public class PermutationSequence {

    public static void main(String[] args) {
        PermutationSequence test = new PermutationSequence();
        System.out.println(test.getPermutation(8, 8590));
    }

    public String getPermutation(int n, int k) {
        int[] factorial = new int[]{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
        List<Integer> numbers = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            numbers.add(i + 1);
        }
        String answer = "";
        k = k - 1;
        for (int i = n; i > 0; i--) {
            int index = k / factorial[i - 1];
//            System.out.println(k);
//            System.out.println(index);
            int number = numbers.get(index);
//            System.out.println(number);
            k = k % factorial[i - 1];

//            System.out.println();
            numbers.remove(index);
            answer += Integer.toString(number);
        }
//        System.out.println(answer);
        return answer;
    }
}
