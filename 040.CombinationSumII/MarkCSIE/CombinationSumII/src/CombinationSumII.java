
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class CombinationSumII {

    public static void main(String[] args) {
        CombinationSumII test = new CombinationSumII();
        int[] testCase1 = new int[]{10, 1, 2, 7, 6, 1, 5};
        List<List<Integer>> testAnswer1 = test.combinationSum2(testCase1, 8);
        System.out.println(testAnswer1.toString());
    }

    public List<List<Integer>> recursiveCombinationSum2(int[] candidates, int target) {
        List<List<Integer>> combinationList = new ArrayList<>();
        for (int i = 0; i < candidates.length; i++) {
            int number = candidates[i];
            if (i > 0 && number == candidates[i - 1]) {
                continue;
            }
            if (target - number > 0) {
                int[] subCandidates = Arrays.copyOfRange(candidates, i + 1, candidates.length);
                List<List<Integer>> subCombinationList = recursiveCombinationSum2(subCandidates, target - number);
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

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Arrays.sort(candidates);
        return recursiveCombinationSum2(candidates, target);
    }
}
