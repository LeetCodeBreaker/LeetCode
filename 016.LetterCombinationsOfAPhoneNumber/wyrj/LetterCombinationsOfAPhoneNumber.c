/* 0ms */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void recursive(char* dig, char* str, int index, char** ret, int* retSize, char** trans) {
    if (index == strlen(dig)) {
        if (0 == index) {
            return ;
        }
        ret[(*retSize)] = (char *)malloc(sizeof(char) * (index+1));
        strncpy(ret[(*retSize)], str, index);
        ret[(*retSize)][index] = '\0';
        (*retSize)++;
        return;
    }
    int i, n = (int)(dig[index] - '0');
    for (i = 0; i < strlen(trans[n]); i++) {
        str[index] = trans[n][i];
        recursive(dig, str, index + 1, ret, retSize, trans);
    }
}
char** letterCombinations(char* digits, int* returnSize) {
    char **ret = (char **)malloc(sizeof(char*) * 1000);
    char *translator[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    char *str = (char *)malloc(sizeof(char) * (strlen(digits)+1));
    (*returnSize) = 0;
    recursive(digits, str, 0, ret, returnSize, translator);
    return ret;
}