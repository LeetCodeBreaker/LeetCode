public class Solution {
    // you need to treat n as an unsigned value
    public int hammingWeight(int n) {
        long n1 = n;
        if( n < 0) {
            n1  =  n + (long)Integer.MAX_VALUE * 2 + 2 ;
        }
      
        int answer = 0;
        while(n1 != 0){
            if(n1 % 2 == 1){
                answer += 1;
            }
            n1 /=2 ;
        }
        
        return answer;
    }
}
