/* 4ms */
bool checkStar(char* str, int len, int index) {
    return (index < len) && ('*' == str[index]);
}
bool isMatch(char* s, char* p) {
    int i, j, offset = 0, sLen = strlen(s), pLen = strlen(p);
    bool table[sLen+1][pLen+1];
    table[0][0] = true;
    for (i = 1; i <= sLen; i++) {
        table[i][0] = false;
    }
    for (j = 1; j + offset <= pLen; j++) {
        if (checkStar(p, pLen, j + offset)) {
            table[0][j] = table[0][j-1];
            offset++;
        } else {
            table[0][j] = false;
        }
    }
    for (i = 1; i <= sLen; i++) {
        offset = 0;
        for (j = 1; j + offset <= pLen; j++) {
            if (checkStar(p, pLen, j + offset)) {
                if (s[i-1] == p[j+offset-1] || '.' == p[j+offset-1]) {
                    table[i][j] = table[i-1][j-1] || table[i-1][j] || table[i][j-1];
                } else {
                    table[i][j] = table[i][j-1];
                }
                offset++;
            } else {
                if (s[i-1] == p[j+offset-1] || '.' == p[j+offset-1]) {
                    table[i][j] = table[i-1][j-1];
                } else {
                    table[i][j] = false;
                }
            }
        }
    }
    return table[sLen][pLen-offset];
}