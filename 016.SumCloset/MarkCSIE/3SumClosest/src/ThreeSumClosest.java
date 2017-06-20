
import java.util.Arrays;

public class ThreeSumClosest {

    public static void main(String[] args) {
        int[] testCase1 = new int[]{-1, 2, 1, -4};
        ThreeSumClosest test = new ThreeSumClosest();
        System.out.println(test.threeSumClosest(testCase1, 1));
    }

    public int threeSumClosest(int[] nums, int target) {
        Arrays.sort(nums);
        int length = nums.length;
        int minDifference = Integer.MAX_VALUE;
        int closestSum = 0;
        for (int i = 0; i < length - 2; i++) {
            int num1 = nums[i];
            int start = i + 1;
            int end = length - 1;
            while (start < end) {
                int num2 = nums[start];
                int num3 = nums[end];
                int sum = num1 + num2 + num3;
                if (sum == target) {
                    return target;
                } else if (sum > target) {
                    if (Math.abs(sum - target) < minDifference) {
                        minDifference = Math.abs(sum - target);
                        closestSum = sum;
                    }
                    end--;
                } else {
                    if (Math.abs(sum - target) < minDifference) {
                        minDifference = Math.abs(sum - target);
                        closestSum = sum;
                    }
                    start++;
                }
            }
        }
        return closestSum;
    }
}
