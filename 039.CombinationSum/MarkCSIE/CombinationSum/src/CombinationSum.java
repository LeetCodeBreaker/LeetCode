
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CombinationSum {

    public static void main(String[] args) {
        CombinationSum test = new CombinationSum();
        int[] testCase1 = new int[]{2, 3, 6, 7};
        List<List<Integer>> testAnswer1 = test.combinationSum(testCase1, 7);
        System.out.println(testAnswer1.toString());
    }
    
    public List<List<Integer>> recursiveCombinationSum(int[] candidates, int target) {
        List<List<Integer>> combinationList = new ArrayList<>();
        for (int i = 0; i < candidates.length; i++) {
            int number = candidates[i];
            if (target - number > 0) {
                int[] subCandidates = Arrays.copyOfRange(candidates, i, candidates.length);
                List<List<Integer>> subCombinationList = recursiveCombinationSum(subCandidates, target - number);
                for (List<Integer> combination : subCombinationList) {
                    combination.add(0, number);
                }
                combinationList.addAll(subCombinationList);
            } else if (target - number == 0) {
                List<Integer> combination = new ArrayList<>();
                combination.add(number);
                combinationList.add(combination);
                break;
            } else {
                break;
            }
        }
        return combinationList;
    }

    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        Arrays.sort(candidates);
        return recursiveCombinationSum(candidates, target);
    }
}
