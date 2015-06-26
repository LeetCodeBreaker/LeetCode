/* 0ms */
char* longestCommonPrefix(char** strs, int strsSize) {
    if (0 == strsSize) {
        return "";
    }
    int index = 0, i, flag = 1;
    char n;
    while(flag) {
        if (index == strlen(strs[0])) {
            break;
        }
        n = strs[0][index];
        for (i = 1; i < strsSize; i++) {
            if (index == strlen(strs[i]) || n != strs[i][index]) {
                flag = 0;
                index--;
                break;
            }
        }
        index++;
    }
    if (0 == index) {
        return "";
    }
    char *ret = (char *)malloc(sizeof(char)*(index+1));
    strncpy(ret, strs[0], index);
    ret[index] = '\0';
    return ret;
}