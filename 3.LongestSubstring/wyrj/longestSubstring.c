/* 8ms */
int findIndex(char* s, int begin, int end) {
    int i;
    for (i = begin; i < end; i++) {
        if (s[i] == s[end]) {
            return i;
        }
    }
    return -1;
}
int lengthOfLongestSubstring(char* s) {
    int length = strlen(s);
    if (0 == length) {
        return 0;
    }
    int ans = 1, nowLen = 1, begin = 0, i;
    for (i = 1; i < length; i++) {
        int index = findIndex(s, begin, i);
        if (-1 < index) {
            nowLen = i - index;
            begin = index + 1;
        } else {
            nowLen++;
            if (nowLen > ans) {
                ans = nowLen;
            }
        }
    }
    return ans;
}