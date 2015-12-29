
import java.util.LinkedList;
import java.util.Queue;

public class RemoveDuplicatesfromSortedArray {

    public static void main(String[] args) {
        int[] testCase = new int[]{1, 2, 3};
        RemoveDuplicatesfromSortedArray test = new RemoveDuplicatesfromSortedArray();
        System.out.println(test.removeDuplicates(testCase));
    }

    public int removeDuplicates(int[] nums) {
        int length = nums.length;
        Queue<Integer> vacancies = new LinkedList<>();
        if (length > 0) {
            int currentNum = nums[0];
            for (int i = 1; i < length; i++) {
                if (currentNum == nums[i]) {
                    vacancies.add(i);
                } else {
                    try {
                        int vacancy = vacancies.remove();
                        nums[vacancy] = nums[i];
                        vacancies.add(i);
                    } catch (Exception ex) {

                    }
                    currentNum = nums[i];
                }
            }
        }
        return length - vacancies.size();
    }
}
