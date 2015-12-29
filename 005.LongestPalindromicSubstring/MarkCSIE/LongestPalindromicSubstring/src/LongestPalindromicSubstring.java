
public class LongestPalindromicSubstring {

    public static void main(String[] args) {
        LongestPalindromicSubstring test = new LongestPalindromicSubstring();
        String testAnswer = test.longestPalindrome("aggbcccba");
        System.out.println(testAnswer);
    }

    // charAt, function call overhead???
    public String longestPalindrome(String s) {
        int length2 = s.length() * 2 + 1;
        char[] s2 = new char[length2];
        for (int i = 0; i < length2; i++) {
            if (i % 2 == 0) {
                s2[i] = '.'; // should find a better character
            } else {
                s2[i] = s.charAt(i / 2);
            }
        }

        int maxIndex = -1;
        int[] pLength = new int[length2];
        pLength[0] = 1;
        int c = 0;
        for (int i = 1; i < length2; i++) {
            if (c + pLength[c] - 1 > i) {
                int ii = c - (i - c);
                if (i + pLength[ii] < c + pLength[c]) {
                    pLength[i] = pLength[ii];
                } else if (i + pLength[ii] == c + pLength[c]) {
                    int count = pLength[ii];
                    try {
                        while (s2[i + count] == s2[i - count]) {
                            count++;
                        }
                    } catch (Exception ex) {
                    }
                    pLength[i] = count;
                } else {
                    pLength[i] = c + pLength[c] - i;
                }
            } else {
                int count = 1;
                try {
                    while (s2[i + count] == s2[i - count]) {
                        count++;
                    }
                } catch (Exception ex) {
                }
                pLength[i] = count;
            }
            if (i + pLength[i] > c + pLength[c]) {
                c = i;
            }

            if (maxIndex == -1 || pLength[i] > pLength[maxIndex]) {
                maxIndex = i;
            }
        }

        if (pLength[maxIndex] % 2 == 0) {
            return s.substring(maxIndex / 2 - pLength[maxIndex] / 2 + 1, maxIndex / 2 + pLength[maxIndex] / 2);
        } else {
            return s.substring(maxIndex / 2 - pLength[maxIndex] / 2, maxIndex / 2 + pLength[maxIndex] / 2);
        }
    }
}
