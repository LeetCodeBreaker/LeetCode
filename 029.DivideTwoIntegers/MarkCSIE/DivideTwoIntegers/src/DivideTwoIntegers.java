
public class DivideTwoIntegers {

    public static void main(String[] args) {
        DivideTwoIntegers test = new DivideTwoIntegers();
        System.out.println(test.divide(23, 5));
    }
    
        public int divide(int dividend, int divisor) {
        if (dividend == Integer.MIN_VALUE && divisor == -1) {
            return Integer.MAX_VALUE;
        }

        long lDividend = Math.abs((long) dividend);
        long lDivisor = Math.abs((long) divisor);

        int quotient = 0;
        while (lDividend >= lDivisor) {
            int k = 0;
            while (lDividend >= (lDivisor << k)) {
                k++;
            }
            lDividend -= (lDivisor << (k - 1));
            quotient += 1 << (k - 1);
        }

        if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            return -quotient;
        } else {
            return quotient;
        }
    }
    
}
