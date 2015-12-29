
public class RomantoInteger {

    public static void main(String[] args) {
        RomantoInteger test = new RomantoInteger();
        System.out.println(test.romanToInt("MCMXCVI"));
    }

    public int romanToInt(String s) {
        int sum = 0;
        boolean V = false;
        boolean X = false;
        boolean L = false;
        boolean C = false;
        boolean D = false;
        boolean M = false;

        for (int i = s.length() - 1; i >= 0; i--) {
            switch (s.charAt(i)) {
                case 'I':
                    if (V || X) {
                        sum--;
                    } else {
                        sum++;
                    }
                    break;
                case 'V':
                    V = true;
                    sum += 5;
                    break;
                case 'X':
                    X = true;
                    if (L || C) {
                        sum -= 10;
                    } else {
                        sum += 10;
                    }
                    break;
                case 'L':
                    L = true;
                    sum += 50;
                    break;
                case 'C':
                    C = true;
                    if (D || M) {
                        sum -= 100;
                    } else {
                        sum += 100;
                    }
                    break;
                case 'D':
                    D = true;
                    sum += 500;
                    break;
                case 'M':
                    M = true;
                    sum += 1000;
                    break;
            }
        }
        return sum;
    }
}
