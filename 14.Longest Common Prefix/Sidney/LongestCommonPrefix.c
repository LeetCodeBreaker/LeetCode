
int allhave(char** strs, int strsSize, int index)
{
    char tmp = strs[0][index];
    for(int i = 0; i < strsSize; i++) {
        if(tmp != strs[i][index]) {
            return 0;
        }
    }
    return 1;
}

char* longestCommonPrefix(char** strs, int strsSize) {
    int min = 2147483647;
    int index = 0;
    for(int i = 0; i < strsSize; i++) {
        if(strlen(strs[i]) < min) {
            min = strlen(strs[i]);
        }
    }
    
    if(min == 2147483647 || min <= 0) {
        return "";
    }
    
    char* ans = (char*)malloc(min);
    if(!ans) {
        return NULL;
    }
    memset(ans, 0, min);
    for(int i = 0; i < min; i++) {
        if(allhave(strs, strsSize, i)) {
            ans[index] = strs[0][i];
            index++;
            ans[index] = 0;
        }
        else {
            break;
        }
    }
    

    return ans;
}