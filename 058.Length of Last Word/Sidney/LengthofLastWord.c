int lengthOfLastWord(char* s) {
    int len = 0;
    for(int i = strlen(s)-1; i >= 0; i--) {
        if(s[i] == ' ') {
            if(len==0) {
                continue;
            }
            else {
                break;
            }
        }
        else {
            len++;
        }
    }
    return len;
}