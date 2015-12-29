
import java.util.Arrays;

public class SortColors {

    public static void main(String[] args) {
        SortColors test = new SortColors();
        int[] testCase = new int[]{2, 2, 0, 0, 2, 0, 2, 1, 0};
        test.sortColors(testCase);
        System.out.println(Arrays.toString(testCase));
    }

    public void sortColors(int[] nums) {
        if (nums == null || nums.length == 0) {
            return;
        }
        int zeroIndex = 0;
        int oneIndex = 0;
        for (int i = 0; i < nums.length; i++) {
//            for (int j = 0; j < nums.length; j++) {
//                System.out.print(nums[j]);
//                System.out.print(" ");
//            }
//            System.out.println();
            if (nums[i] == 0) {
                nums[i] = 2;
                nums[oneIndex] = 1;
                oneIndex++;
                nums[zeroIndex] = 0;
                zeroIndex++;
            } else if (nums[i] == 1) {
                nums[i] = 2;
                nums[oneIndex] = 1;
                oneIndex++;
            }
        }
    }

}
