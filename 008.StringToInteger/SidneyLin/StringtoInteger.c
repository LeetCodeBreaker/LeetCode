int myAtoi(char* str) {
    
    int index = 0;
    int negflag = 0;
    
    int len = strlen(str);
    int sum = 0;
    
    if(len == 0) {
        return 0;
    }
    
    while(1) {
        if(str[index] != ' ') {
            break;
        }
        index++;
    }
    
    if(str[index] == '-') {
        negflag = 1;
        index++;
    }
    else if(str[index] == '+') {
        index++;
    }
    else {
        
    }
    
    for(int i = index; i < len; i++) {
		if(str[i] <= '9' && str[i] >= '0') {
			if(negflag) {
			    if(sum < (INT_MIN + (str[i] -'0')) / 10) {
			        return INT_MIN;
			    }
			    else {
			        sum = (sum * 10) - (str[i] -'0');
			    }
			}
			else {
			    if(sum > (INT_MAX - (str[i] -'0')) / 10) {
			        return INT_MAX;
			    }
			    else {
			        sum = (sum * 10) + (str[i] -'0');
			    }
			}
		}
		else {
		    break;
		}
    }
    
    return sum;
}