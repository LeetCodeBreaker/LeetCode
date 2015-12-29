public class Solution {
    public int lengthOfLastWord(String s) {
        String[] subStrs = s.split(" ");
        if(subStrs.length == 0){
            return 0;
        }else{
            return subStrs[subStrs.length-1].length();
        }
    }
}
