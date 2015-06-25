/* 8ms */
char* convert(char* s, int numRows) {
    if (1 == numRows) {
        return s;
    }
    int len = strlen(s);
    char* ret = (char *)malloc(sizeof(char)*(len+1));
    ret[len] = '\0';
    int retIndex = 0, pingpongMax = (numRows - 2) * 2;
    int i, j, next;
    for (i = 0; i < numRows; i++) {
        j = i;
        next = 2 * i - 1;
        while(j < len) {
            ret[retIndex++] = s[j];
            if (next < pingpongMax) {
                next = pingpongMax - next;
            }
            j += next + 1;
        }
    }
    return ret;
}