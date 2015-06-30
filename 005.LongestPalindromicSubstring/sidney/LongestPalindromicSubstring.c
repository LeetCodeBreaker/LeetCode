int getmaxlen(char* s, int start, int *left, int *right)
{
    int l = 0, r = 0;
    while(1)
    {
        if(start+l < 0) {
            break;
        }
        if(start+r > strlen(s) -1) {
            break;
        }
        
        if(s[start+l] != s[start+r]) {
            break;
        }
        
        *left = start+l;
        *right = start+r;
        l--;
        r++;
    }
    return *right - *left + 1;
}

int getmaxlen2(char* s, int start, int start2, int *left, int *right)
{
    int l = 0, r = 0;
    while(1)
    {
        if(start+l < 0) {
            break;
        }
        if(start2+r > strlen(s) -1) {
            break;
        }
        
        if(s[start+l] != s[start2+r]) {
            break;
        }
        
        *left = start+l;
        *right = start2+r;
        l--;
        r++;
    }
    return *right - *left + 1;
}

char* longestPalindrome(char* s) {
    int  max = 0, len = 0, left = 0, right = 0;
    char *ans;
    int length = strlen(s);

    ans = (char*)malloc(length+1);
    memset(ans, 0 , length+1);
    
    for(int i = 0; i < length; i++) {
        len = getmaxlen(s, i, &left, &right);
        if(len > max) {
            max = len;
            memset(ans, 0 , length+1);
            strncpy(ans, &s[left], right-left+1);
        }

    }
    
    for(int i = 1; i < length; i++) {
        len = getmaxlen2(s, i-1, i, &left, &right);
        if(len > max) {
            max = len;
            memset(ans, 0 , length+1);
            strncpy(ans, &s[left], right-left+1);
        }
    }

    return ans;
}