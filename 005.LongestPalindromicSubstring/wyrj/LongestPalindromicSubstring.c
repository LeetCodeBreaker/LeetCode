/* 24ms */
int findPalindrome(char* s, int start, int end) {
    int len = strlen(s);
    while(0 <= start && len > end && s[start] == s[end]) {
        start--;
        end++;
    }
    return end - start - 1;
}
int max(int a, int b) {
    return (a > b) ? a : b;
}
char* longestPalindrome(char* s) {
    int len = strlen(s), mid, palLen = 0, palMid = 0;
    for(mid = 0; mid < len; mid++) {
        int testLen = max(findPalindrome(s, mid-1, mid+1), findPalindrome(s, mid, mid+1));
        if (testLen > palLen) {
            palLen = testLen;
            palMid = mid;
        }
    }
    char *ret = (char *)malloc(sizeof(char) * (palLen + 1));
    strncpy(ret, &s[palMid - (palLen - 1) / 2], palLen);
    ret[palLen] = '\0';
    return ret;
}