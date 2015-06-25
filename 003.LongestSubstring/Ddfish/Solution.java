public class Solution {
    public int lengthOfLongestSubstring(String s) {
        int[] flags = new int[256];
        int answer = 0 ;
        int max = s.length();
        int i = 0 ;
        int j = 0 ;
        
        while( j<max ){
       
            if(flags[s.charAt(j)] == 1){
                flags[s.charAt(i)] = 0;
                i++;
            }else{
                flags[s.charAt(j)] = 1;
                if(j-i+1>answer){
				            answer = j-i+1;
                }
                j++;
            }
        }
        
        return answer;
    }
}
