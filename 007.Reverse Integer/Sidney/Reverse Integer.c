void my_itoa(int x, char* str)
{
    int index = 0;
    
    do{
      str[index]= x % 10 + '0';
      index++;
    }
    while((x = x/10)>0);
}

int my_atoi(char *str) 
{
    int len = strlen(str);
    int sum = 0;
    int tmp = 0;
    sum += (str[0] - '0');
    for(int i = 1 ; i < len; i ++) {
        tmp = sum;
        sum = sum * 10;
        if(sum/10 != tmp) {
            return 0;
        }
        
        tmp = sum;
        sum += (str[i] - '0');
        if(sum < tmp) {
            return 0;
        }
    }
    
    return sum;
}

int reverse(int x) {
    char str[1024] = {0};
    int tmp = 0;
    if(x < 0) {
        x = -x;
        if(x < 0) {
            return 0;
        }
        tmp = reverse(x)*(-1);
        if(tmp > 0) {
            return 0;
        }
        return tmp;
    }
    
    my_itoa(x, str);
    
    return my_atoi(str);
}