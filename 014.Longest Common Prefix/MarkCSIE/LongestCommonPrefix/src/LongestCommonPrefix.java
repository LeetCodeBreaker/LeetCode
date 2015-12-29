
public class LongestCommonPrefix {

    public static void main(String[] args) {
        LongestCommonPrefix test = new LongestCommonPrefix();
        String[] testCase1 = {"123", "12"};
        System.out.println(test.longestCommonPrefix(testCase1));
    }

    public String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        } else if (strs.length == 1) {
            return strs[0];
        }

        String lcp = "";
        while (true) {
            int i = 0;
            int index = lcp.length();
            for (i = 0; i < strs.length - 1; i++) {
                if (index >= strs[i].length() || index >= strs[i + 1].length() || strs[i].charAt(index) != strs[i + 1].charAt(index)) {
                    return lcp;
                }
            }
            if (i == strs.length - 1) {
                lcp += strs[0].charAt(index);
            }
        }
    }
}
