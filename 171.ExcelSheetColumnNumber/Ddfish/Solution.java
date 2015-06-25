public class Solution {
    public int titleToNumber(String s) {
        char[] c = s.toCharArray();
        int answer = 0;
        for (int i = 0 ; i < c.length ; i++){
            answer = answer * 26;
            answer += c[i] - 'A' + 1;
        }
        return answer;
        
    }
}
