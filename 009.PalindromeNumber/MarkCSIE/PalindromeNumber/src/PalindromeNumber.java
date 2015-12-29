
public class PalindromeNumber {

    public static void main(String[] args) {
        PalindromeNumber test = new PalindromeNumber();
        boolean testAnswer1 = test.isPalindrome(123321);
        System.out.println(testAnswer1);
    }

    public boolean isPalindrome(int x) {
        if (x < 0) {
            return false;
        }

        int length = (int) Math.log10(x);
        for (int i = 0; i <= length / 2; i++) {
            int left = (int) (x / Math.pow(10, length - i)) % 10;
            int right = (int) (x / Math.pow(10, i)) % 10;
            if (left != right) {
                return false;
            }
        }
        return true;
    }
}
