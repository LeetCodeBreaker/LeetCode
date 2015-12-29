
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;


public class FourSum {

    public static void main(String[] args) {
        int[] testCase1 = new int[]{1, 0, -1, 0, -2, 2};
        FourSum test = new FourSum();
        List<List<Integer>> testAnswer1 = test.fourSum(testCase1, 0);
        System.out.println(testAnswer1.toString());
    }
    
    public List<List<Integer>> fourSum(int[] nums, int target) {
        List<List<Integer>> answerList = new ArrayList<>();
        int length = nums.length;
        if (length < 4) {
            return answerList;
        }
        Arrays.sort(nums);

        for (int i = 0; i < length - 3; i++) {
            int num1 = nums[i];
            if (i != 0 && num1 == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < length - 2; j++) {
                int num2 = nums[j];
                if (j != i + 1 && num2 == nums[j - 1]) {
                    continue;
                }

                int start = j + 1;
                int end = length - 1;
                while (start < end) {
                    int num3 = nums[start];
                    int num4 = nums[end];
                    int sum = num1 + num2 + num3 + num4;
                    if (sum == target) {
                        List<Integer> quadruplet = new ArrayList<>();
                        quadruplet.add(num1);
                        quadruplet.add(num2);
                        quadruplet.add(num3);
                        quadruplet.add(num4);
                        answerList.add(quadruplet);
                        start++;
                        end--;
                        while (start < end && nums[end] == nums[end + 1]) {
                            end--;
                        }
                        while (start < end && nums[start] == nums[start - 1]) {
                            start++;
                        }

                    } else if (sum < target) {
                        start++;
                    } else {
                        end--;
                    }
                }
            }
        }
        return answerList;
    }
}
