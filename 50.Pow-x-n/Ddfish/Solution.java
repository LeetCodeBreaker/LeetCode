public class Solution {
    public double myPow(double x, int n) {
        double a = 1.0;
        if(x == 0){
            return 0;
        }
        if(n == 0){
            return 1;
        }
        if(n == 1){
            return x;
        }
        
        if(n < 0){
            x  =  1 / x ;
            n  =  n * (-1);
        }
        double y = myPow(x,n/2);
        if( n % 2 == 0){
            return y * y;
        }else{
            return x * y * y;
        }
    }
}
