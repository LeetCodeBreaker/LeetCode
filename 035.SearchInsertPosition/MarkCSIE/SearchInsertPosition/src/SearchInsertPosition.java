
public class SearchInsertPosition {

    public static void main(String[] args) {
        SearchInsertPosition test = new SearchInsertPosition();
        int[] testCase1 = new int[]{1, 3, 5, 6};
        System.out.println(test.searchInsert(testCase1, 5));
    }
    
    // [1,3,5,6]
    public int searchInsert(int[] nums, int target) {
        int left = 0;
        int right = nums.length - 1;
        while (left <= right) {
            int middle = (left + right) / 2;
            if (nums[middle] < target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
        }
        return left;
    }
}
