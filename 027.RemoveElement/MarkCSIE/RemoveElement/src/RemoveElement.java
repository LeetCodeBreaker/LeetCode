
public class RemoveElement {

    public static void main(String[] args) {
        int[] testCase = new int[]{4, 5};
        RemoveElement test = new RemoveElement();
        System.out.println(test.removeElement(testCase, 5));
    }

    public int removeElement(int[] nums, int val) {
        int answer = nums.length;
        for (int i = 0; i < answer; i++) {
            if (nums[i] == val) {
                for (int j = i; j < nums.length - 1; j++) {
                    nums[j] = nums[j + 1];
                }
                answer--;
                i--;
            }
        }
        return answer;
    }
}
