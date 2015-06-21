static int AlphabetAry[256] = {0};
class Solution {
public:
        int lengthOfLongestSubstring(string s) {
            int maxlen = 0, len = 0;
            int size = s.length();
            memset(AlphabetAry, 0, sizeof(AlphabetAry));
            for(int head = 0; head < size; head++) {
                len = 0;
                for(int tail = head; tail < size; tail++) {
                    if(AlphabetAry[s[tail]-'0'] == 0) {
                        AlphabetAry[s[tail]-'0'] = 1;
                        len++;
                        if(len > maxlen) {
                            maxlen = len;
                        }
                    }
                    else {
                        memset(AlphabetAry, 0, sizeof(AlphabetAry));
                        break;
                    }
                }
            }

            return maxlen;
        }
};