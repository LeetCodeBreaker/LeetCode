
import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

public class SlidingWindowMaximum {

    public static void main(String[] args) {
        SlidingWindowMaximum test = new SlidingWindowMaximum();
        int[] testCase = new int[]{1, 3, 1, 2, 0, 5};
        System.out.println(Arrays.toString(test.maxSlidingWindow(testCase, 3)));
    }

    public int[] maxSlidingWindow(int[] nums, int k) {
        if (nums.length == 0) {
            return new int[]{};
        }

        int[] answer = new int[nums.length - k + 1];
        Deque<Integer> deque = new ArrayDeque<>();

        // First round
        for (int i = 0; i < k; i++) {
            while (!deque.isEmpty() && nums[i] >= nums[deque.getLast()]) {
                deque.removeLast();
            }
            deque.add(i);
        }
        answer[0] = nums[deque.getFirst()];

        for (int i = k; i < nums.length; i++) {
            if (deque.getFirst() == i - k) {
                deque.removeFirst();
            }
            while (!deque.isEmpty() && nums[i] >= nums[deque.getLast()]) {
                deque.removeLast();
            }
            deque.add(i);
            answer[i - k + 1] = nums[deque.getFirst()];
        }

        return answer;
    }

}
