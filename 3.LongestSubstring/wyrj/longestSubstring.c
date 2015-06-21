/* 8ms */
/* Sidney improve findIndex by table */
int table[256] = {0};
int findIndex(char* s, int begin, int end) {
    int index = table[s[end]];
    table[s[end]] = end;
    if (index >= begin) {
        return index;
    }
    return -1;
}
int lengthOfLongestSubstring(char* s) {
    int length = strlen(s);
    if (0 == length) {
        return 0;
    }
    int ans = 1, nowLen = 1, begin = 0, i;
    for (i = 0; i < 256; i++) {
        table[i] = -1;
    }
    table[s[0]] = 0;
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