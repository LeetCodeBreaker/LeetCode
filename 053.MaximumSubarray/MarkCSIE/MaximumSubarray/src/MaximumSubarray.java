
public class MaximumSubarray {

    public static void main(String[] args) {
        MaximumSubarray test = new MaximumSubarray();
        int[] testCase1 = new int[]{-2, 1, -3, 4, -1, 2, 1, -5, 4};
        System.out.println(test.maxSubArray(testCase1));
    }

    //    public int maxSubArray(int[] nums) {
//        int max = nums[0];
//        int temp = nums[0];
//        for (int i = 1; i < nums.length; i++) {
//            int num = nums[i];
//                       
//            if (num > temp && temp < 0) {
//                temp = num;
//            } else {
//                temp = temp + num;
//            }
//            
//            if (temp > max) {
//                max = temp;
//            }
//        }
//        return max;
//    }
    // Divide and Conquer
    public int maxSubArray(int[] nums) {
        if (nums.length == 0) {
            return 0;
        }
        return recursiveMaxSubArray(nums, 0, nums.length - 1);
    }

    int recursiveMaxSubArray(int[] nums, int left, int right) {
        if (right == left) {
            return nums[left];
        }
        int middle = (left + right) / 2;

        int leftAns = recursiveMaxSubArray(nums, left, middle);
        int rightAns = recursiveMaxSubArray(nums, middle + 1, right);

        int leftmax = nums[middle];
        int temp = 0;
        for (int i = middle; i >= left; i--) {
            temp += nums[i];
            if (temp > leftmax) {
                leftmax = temp;
            }
        }

        int rightmax = nums[middle + 1];
        temp = 0;
        for (int i = middle + 1; i <= right; i++) {
            temp += nums[i];
            if (temp > rightmax) {
                rightmax = temp;
            }
        }
        return Math.max(Math.max(leftAns, rightAns), leftmax + rightmax);
    }

}
