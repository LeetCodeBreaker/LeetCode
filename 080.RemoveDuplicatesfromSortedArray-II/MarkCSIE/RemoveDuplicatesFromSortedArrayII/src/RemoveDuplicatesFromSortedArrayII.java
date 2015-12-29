
import java.util.LinkedList;
import java.util.Queue;

public class RemoveDuplicatesFromSortedArrayII {

    public static void main(String[] args) {
        RemoveDuplicatesFromSortedArrayII test = new RemoveDuplicatesFromSortedArrayII();
        int[] testCase = new int[]{1, 2, 3};
        System.out.println(test.removeDuplicates(testCase));
    }

    public int removeDuplicates(int[] nums) {
        int length = nums.length;
        Queue<Integer> vacancies = new LinkedList<>();
        if (length > 0) {
            int currentNum = nums[0];
            boolean twice = false;
            for (int i = 1; i < length; i++) {
                if (currentNum == nums[i]) {
                    if (twice) {
                        vacancies.add(i);
                    } else {
                        try {
                            int vacancy = vacancies.remove();
                            nums[vacancy] = nums[i];
                            vacancies.add(i);
                        } catch (Exception ex) {

                        }
                    }
                    twice = true;
                } else {
                    twice = false;
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
