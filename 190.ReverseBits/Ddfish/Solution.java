public class Solution {
    // you need treat n as an unsigned value
    public int reverseBits(int n) {
        long l = n & 0x00000000ffffffffL;
        int answer = 0;
        for(int i = 0 ; i< 32 ; i++){
            answer *= 2;
            answer += l % 2;
            l /= 2;
        }
        return answer;
        
    }
}
