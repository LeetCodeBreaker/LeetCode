
import java.util.Arrays;
import java.util.HashMap;

public class TwoSum {

    public static void main(String[] args) {
        TwoSum test = new TwoSum();
        int[] answer = test.twoSum(new int[]{-1, -2, -3, -4, -5}, -8);
        System.out.println(Arrays.toString(answer));
    }

    public int[] twoSum(int[] nums, int target) {
        int[] answer = {-1, -1};
        int length = nums.length;
        HashMap<Integer, Integer> numbers = new HashMap<>();
        for (int i = 0; i < length; i++) {
            if (numbers.containsKey(nums[i])) {
                answer[0] = numbers.get(nums[i]) + 1;
                answer[1] = i + 1;
                return answer;
            } else {
                numbers.put(target - nums[i], i);
            }
        }
        return answer;
    }
}
