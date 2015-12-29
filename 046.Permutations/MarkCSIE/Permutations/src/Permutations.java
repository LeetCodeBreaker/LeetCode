
import java.util.ArrayList;
import java.util.List;


public class Permutations {

    public static void main(String[] args) {
        Permutations test = new Permutations();
        int[] testCase1 = new int[]{1, 2, 3};
        List<List<Integer>> testAnswer1 = test.permute(testCase1);
        System.out.println(testAnswer1.toString());
    }
    
        // no duplicate in nums
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> combinationList = new ArrayList<>();
        if (nums.length == 1) {
            List<Integer> combination = new ArrayList<>();
            combination.add(nums[0]);
            combinationList.add(combination);
        } else {
            for (int i = 0; i < nums.length; i++) {
                int[] subNums = new int[nums.length - 1];
                System.arraycopy(nums, 0, subNums, 0, i);
                System.arraycopy(nums, i + 1, subNums, i, nums.length - i - 1);
                List<List<Integer>> subCombinationList = permute(subNums);
                int number = nums[i];
                for (List<Integer> combination : subCombinationList) {
                    combination.add(0, number);
                }
                combinationList.addAll(subCombinationList);
            }
        }
        return combinationList;
    }
    
}
