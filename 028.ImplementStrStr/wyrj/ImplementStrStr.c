/* 92ms */
int strStr(char* haystack, char* needle) {
    int backward[strlen(needle)];
    backward[0] = -1;
    int i = 0, j = 0;
    for (j = 1; j < strlen(needle); j++) {
        if (needle[j] == needle[i]) {
            backward[j] = i;
            i++;
        } else {
            backward[j] = -1;
            i = 0;
        }
    }
    i = 0;
    j = 0;
    while (true) {
        if (j == strlen(needle)) {
            return i - strlen(needle);
        } else if (i == strlen(haystack)) {
            return -1;
        } else if (needle[j] == haystack[i]) {
            i++;
            j++;
        } else if (0 != j) {
            j = backward[j-1]+1;
        } else {
            i++;
        }
    }
}