
public class PowXn {

    public static void main(String[] args) {
        PowXn test = new PowXn();
        System.out.println(test.myPow(-9, 3));
    }

    public double myPow(double x, int n) {
        if (n == 0) {
            return 1;
        }

        double v = myPow(x, n / 2);
        if (n % 2 == 0) {
            return v * v;
        } else if (n > 0) {
            return v * v * x;
        } else {
            return v * v / x;
        }
    }
}
