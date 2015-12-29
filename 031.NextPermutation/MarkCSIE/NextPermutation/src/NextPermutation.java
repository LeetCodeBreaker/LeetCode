
import java.util.Arrays;

public class NextPermutation {

    public static void main(String[] args) {
        int[] testCase1 = new int[]{1, 2, 3};
        System.out.print(Arrays.toString(testCase1) + "->");
        NextPermutation test = new NextPermutation();
        test.nextPermutation(testCase1);
        System.out.println(Arrays.toString(testCase1));
    }

    public void nextPermutation(int[] nums) {
        for (int i = nums.length - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                for (int j = nums.length - 1; j >= i + 1; j--) {
                    if (nums[j] > nums[i]) {
                        int temp = nums[i];
                        nums[i] = nums[j];
                        nums[j] = temp;

                        // reverse
                        int start = i + 1;
                        int end = nums.length - 1;
                        while (start < end) {
                            temp = nums[start];
                            nums[start] = nums[end];
                            nums[end] = temp;
                            start++;
                            end--;
                        }
                        return;
                    }
                }
            }

        }

        // reverse
        int start = 0;
        int end = nums.length - 1;
        while (start < end) {
            int temp = nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
}
