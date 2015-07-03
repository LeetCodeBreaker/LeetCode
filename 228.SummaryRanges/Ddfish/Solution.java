public class Solution {
    public List<String> summaryRanges(int[] nums) {
        List<String> answer = new ArrayList<>();
        if(nums.length == 0){
            return answer;
        }
        
        int start = nums[0];
        int end = nums[0];
        for(int i = 1 ; i < nums.length ; i++){
            if(nums[i] == end + 1){
                end = nums[i];
            }else{
                if(start == end){
                    answer.add(""+start);   
                }else{
                    String str = ""+start+"->"+end;
                    answer.add(str);
                }
                start = nums[i];
                end   = nums[i];
            }
        }
        
        if(start == end){
                    answer.add(""+start);   
          }else{
                    String str = ""+start+"->"+end;
                    answer.add(str);
        }
        return answer;
        
    }
}
