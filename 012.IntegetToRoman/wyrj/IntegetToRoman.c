/* 32 */
char* intToRoman(int num) {
    char *ret = (char *)malloc(sizeof(char)*1000);
    int index = 0, i, len;
    int translatee[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *translator[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    for (i = 0; i < 13; i++) {
        while(num >= translatee[i]) {
            num -= translatee[i];
            len = strlen(translator[i]);
            strncpy(&ret[index], translator[i], len);
            index += len;
        }
    }
    ret[index] = '\0';
    return ret;
}