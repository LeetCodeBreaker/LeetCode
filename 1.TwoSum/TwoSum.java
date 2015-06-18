package twosum;

public class TwoSum {
    
    public static void main(String[] args) {
        TwoSum solution = new TwoSum();
        int[] answer = solution.twoSum(new int[]{2, 7, 11, 15}, 9);
        System.out.println(answer[0]);
        System.out.println(answer[1]);
    }

    public int[] twoSum(int[] nums, int target) {
        int[] answer = {-1, -1};
        for (int i = 0; i < nums.length; i++) {
            for (int j = i+1; j < nums.length; j++) {
                if (nums[i] + nums[j] == target) {
                    answer[0] = i + 1;
                    answer[1] = j + 1;
                    return answer;
                }
            }
        }
        return answer;
    }

}
