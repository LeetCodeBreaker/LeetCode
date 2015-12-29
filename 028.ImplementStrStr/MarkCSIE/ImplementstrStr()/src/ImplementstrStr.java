public class ImplementstrStr {

    public static void main(String[] args) {
        ImplementstrStr test = new ImplementstrStr();
        System.out.println(test.strStr("mississippi", "issi"));
    }
    
    public int strStr(String haystack, String needle) {
        // NAIVE
//        if (needle.isEmpty()) {
//            return 0;
//        } else if (needle.length() > haystack.length()) {
//            return -1;
//        }
//        
//        int haystackLen = haystack.length();
//        int needleLen = needle.length();
//        char[] haystackArray = haystack.toCharArray();
//        char[] needleArray = needle.toCharArray();
//        int searchSpace = haystackLen - needleLen + 1;
//        for (int i = 0; i < searchSpace; i++) {
//            int count = i;
//            for (int j = 0; j < needleLen; j++) {
//                if (haystackArray[count] != needleArray[j]) {
//                    break;
//                } else {
//                    count++;
//                }
//            }
//            if (count - i == needleLen) {
//                return i;
//            }
//        }
//        return -1;

        // KMP
        if (needle.isEmpty()) {
            return 0;
        } else if (needle.length() > haystack.length()) {
            return -1;
        }

        int[] suffixPrefixTable = new int[needle.length()];
        int suffixPrefixLen = 0;
        suffixPrefixTable[0] = 0;
        for (int i = 1; i < needle.length(); i++) {
            if (needle.charAt(i) == needle.charAt(suffixPrefixLen)) {
                suffixPrefixLen++;
            } else {
                suffixPrefixLen = 0;
                if (needle.charAt(i) == needle.charAt(suffixPrefixLen)) {
                    suffixPrefixLen++;
                }
            }
            suffixPrefixTable[i] = suffixPrefixLen;
        }
//        System.out.println(Arrays.toString(suffixPrefixTable));

        int needleIndex = 0;
        int validShift = -1;
        for (int i = 0; i < haystack.length(); i++) {
            if (haystack.charAt(i) == needle.charAt(needleIndex)) {
                needleIndex++;
            } else {
                if (needleIndex != 0) {
                    needleIndex = suffixPrefixTable[needleIndex - 1];
                    i--;
                }
            }

            if (needleIndex == needle.length()) {
                validShift = i - needle.length() + 1;
                break;
            } else if (i + (needle.length() - needleIndex) > haystack.length()) {
                break;
            }
        }
        return validShift;
    }
}
