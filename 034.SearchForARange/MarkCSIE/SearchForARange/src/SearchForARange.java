
import java.util.Arrays;

public class SearchForARange {

    public static void main(String[] args) {
        SearchForARange test = new SearchForARange();
        int[] testCase1 = new int[]{5, 7, 7, 8, 8, 10};
        int[] testAnswer1 = test.searchRange(testCase1, 8);
        System.out.println(Arrays.toString(testAnswer1));
    }

    //[5, 7, 7, 8, 8, 10]
    public int[] searchRange(int[] nums, int target) {
        // find lower bound
        int lowerLeft = 0;
        int lowerRight = nums.length - 1;
        while (lowerLeft <= lowerRight) {
            int middle = (lowerLeft + lowerRight) / 2;
            if (nums[middle] < target) {
                lowerLeft = middle + 1;
            } else {
                lowerRight = middle - 1;
            }
        }

        // find upper bound
        int upperLeft = 0;
        int upperRight = nums.length - 1;
        while (upperLeft <= upperRight) {
            int middle = (upperLeft + upperRight) / 2;
            if (nums[middle] <= target) {
                upperLeft = middle + 1;
            } else {
                upperRight = middle - 1;
            }
        }
//        System.out.println(lowerLeft);
//        System.out.println(upperRight);
        if (lowerLeft <= upperRight) {
            return new int[]{lowerLeft, upperRight};
        } else {
            return new int[]{-1, -1};
        }

//        O(nlog(n))
//        if (nums.length == 1) {
//            if (nums[0] == target) {
//                return new int[]{0, 0};
//            } else {
//                return new int[]{-1, -1};
//            }
//        } else { 
//            int[] frontPart = Arrays.copyOfRange(nums, 0, (nums.length-1) / 2 + 1);
//            int[] frontRange = searchRange(frontPart, target);
//            int[] backPart = Arrays.copyOfRange(nums, (nums.length - 1) / 2 + 1, nums.length);
//            int[] backRange = searchRange(backPart, target);
//            if (backRange[0] != -1) {
//                backRange[0] += (nums.length-1) / 2 + 1;
//            }
//            if (backRange[1] != -1) {
//                backRange[1] += (nums.length-1) / 2 + 1;
//            }
//            
//            int[] range = new int[frontRange.length + backRange.length];
//            System.arraycopy(frontRange, 0, range, 0, frontRange.length);
//            System.arraycopy(backRange, 0, range, frontRange.length, backRange.length);
//
//            int frontIndex = -1;
//            if (range[0] != -1) {
//                frontIndex = range[0];
//            } else if (range[1] != -1) {
//                frontIndex = range[1];
//            } else if (range[2] != -1) {
//                frontIndex = range[2];
//            } else if (range[3] != -1) {
//                frontIndex = range[3];
//            }
//            
//            int backIndex = -1;
//            if (range[3] != -1) {
//                backIndex = range[3];
//            } else if (range[2] != -1) {
//                backIndex = range[2];
//            } else if (range[1] != -1) {
//                backIndex = range[1];
//            } else if (range[0] != -1) {
//                backIndex = range[0];
//            }
//            return new int[]{frontIndex, backIndex};
//        }  
    }
}
