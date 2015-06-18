public class Solution {
    public int[] twoSum(int[] nums, int target) {
        
        java.util.Map<Integer, Integer> map = new java.util.HashMap<Integer, Integer>();
        for(int i = 0 ; i < nums.length; i++){
	    	
	    		if(map.containsKey(nums[i])){
	    		    return new int[]{map.get(nums[i])+1,i+1};
	    		}else{
	    		    map.put(target - nums[i],i);
	    		}
	    
	    }
	    return new int[]{-1 ,-1};
    }
}
