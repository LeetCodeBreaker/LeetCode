int getlettervalue(char letter) {  
    if(letter == 'I') {
        return 1;  
    }
    else if(letter == 'V') {
        return 5;  
    }
    else if(letter == 'X') {
        return 10;  
    }
    else if(letter == 'L') {
        return 50;  
    }
    else if(letter == 'C') {
        return 100;  
    }
    else if(letter == 'D') {
        return 500;  
    }
    else if(letter == 'M') {
        return 1000;  
    }    
}  

int romanToInt(char* s) {
    int len = strlen(s);
    int ans = 0;
    ans += getlettervalue(s[0]);
    for(int i = 1; i < len; i++) {
        if(getlettervalue(s[i]) > getlettervalue(s[i-1])) {
            ans -= getlettervalue(s[i-1]);
            ans -= getlettervalue(s[i-1]);
            ans += getlettervalue(s[i]);
        }
        else {
            ans += getlettervalue(s[i]);
        }
    }
    return ans;
    
}