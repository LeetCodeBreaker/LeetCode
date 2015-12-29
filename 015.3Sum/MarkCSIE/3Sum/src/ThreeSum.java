
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class ThreeSum {

    public static void main(String[] args) {
        ThreeSum test = new ThreeSum();
        int[] testCase1 = new int[]{-1, 0, 1, 2, -1, -4};
        List<List<Integer>> testAnswer1 = test.threeSum(testCase1);
        System.out.println(testAnswer1.toString());
    }

    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> answerList = new ArrayList<>();
        int length = nums.length;
        if (length < 3) {
            return answerList;
        }
        Arrays.sort(nums);
//        System.out.println(Arrays.toString(nums));
        for (int i = 0; i < length - 2; i++) {
            int num1 = nums[i];
            if (i != 0 && num1 == nums[i - 1]) {
                continue;
            }

            int start = i + 1;
            int end = length - 1;
            while (start < end) {
                int num2 = nums[start];
                int num3 = nums[end];
                int sum = num1 + num2 + num3;
                if (sum == 0) {
                    List<Integer> triplet = new ArrayList<>();
                    triplet.add(num1);
                    triplet.add(num2);
                    triplet.add(num3);
                    answerList.add(triplet);
                    start++;
                    end--;
                    while (start < end && nums[end] == nums[end + 1]) {
                        end--;
                    }
                    while (start < end && nums[start] == nums[start - 1]) {
                        start++;
                    }

                } else if (sum < 0) {
                    start++;
                } else {
                    end--;
                }
            }
        }
        return answerList;
    }
}
