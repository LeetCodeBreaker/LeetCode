/* 28ms */
int romanToInt(char* s) {
    int ret = 0;
    int index = 0, i, len;
    int translator[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    char *translatee[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    for (i = 0; i < 13; i++) {
        len = strlen(translatee[i]);
        while(index < strlen(s) && 0 == strncmp(&s[index], translatee[i], len)) {
            index += len;
            ret += translator[i];
        }
    }
    return ret;
}