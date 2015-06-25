public class Solution {
    public boolean containsDuplicate(int[] nums) {
        if(nums.length == 0){
            return false;
        }
        java.util.LinkedList<Integer> list = new  java.util.LinkedList<>();
        list.add(nums[0]);
        for(int i = 1 ; i < nums.length ; i++){
            if(nums[i] < list.getFirst()){
                list.addFirst(nums[i]);
            }else if(nums[i] > list.getLast()){
                list.addLast(nums[i]);
            }else if(list.contains(nums[i])){
                return true;
            }
        }
        return false;
    }
}
