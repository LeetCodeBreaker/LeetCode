/* 0ms */
/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
void recursive(int left, int right, int index, char* str, char** ret, int* retSize) {
    if (0 == left) {
        while (right--) {
            str[index++] = ')';
        }
        ret[(*retSize)] = (char *)malloc(sizeof(char)*(strlen(str)+1));
        strncpy(ret[(*retSize)], str, strlen(str)+1);
        (*retSize)++;
        return ;
    }
    str[index] = '(';
    recursive(left - 1, right, index + 1, str, ret, retSize);
    if (left < right) {
        str[index] = ')';
        recursive(left, right - 1, index + 1, str, ret, retSize);
    }
}
char** generateParenthesis(int n, int* returnSize) {
    *returnSize = 0;
    char** ret = (char **)malloc(sizeof(char *) * 10000);
    char* str = (char *)malloc(sizeof(char) * (2 * n + 1));
    str[2 * n] = '\0';
    recursive(n, n, 0, str, ret, returnSize);
    return ret;
}