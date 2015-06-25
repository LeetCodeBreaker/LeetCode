public class Solution {
    public int reverse(int x) {
        
        long y = 0;
        int flag = (x >= 0) ? 1 : -1;
        x *= flag;
               
        while(x != 0){
            y = y * 10 + x % 10;
            x = x / 10;
        }
        y  = y * flag;
        
        if(y >  Integer.MAX_VALUE){
        	
		   return 0;
        }
	    if (y < Integer.MIN_VALUE){
		   return 0;
	    }
	    return (int) y;
        
    }
}
