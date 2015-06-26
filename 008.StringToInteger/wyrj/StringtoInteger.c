/* 4ms */
int myAtoi(char* str) {
    int start = 0;
    while(' ' == str[start]) {
        start++;
    }
    int ret = 0, INTMAX = 2147483647, INTMIN = -2147483648, index, n;
    if ('-' == str[start]) {
        index = start + 1;
        while('0' <= str[index] && '9' >= str[index]) {
            n = str[index++] - '0';
            if ((INTMIN + n) / 10 > ret) {
                return INTMIN;
            }
            ret = ret * 10 - n;
        }
    } else {
        index = ('+' == str[start]) ? start + 1 : start;
        while('0' <= str[index] && '9' >= str[index]) {
            n = str[index++] - '0';
            if ((INTMAX - n) / 10 < ret) {
                return INTMAX;
            }
            ret = ret * 10 + n;
        }
    }
    return ret;
}