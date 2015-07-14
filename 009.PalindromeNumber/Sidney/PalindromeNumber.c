int getdigitnumber(int x)
{
    int count = 0;
    while(1)
    {
        if(x /10 != 0) {
            count++;
            x = x / 10;
        }
        else {
            break;
        }
    }
    return count;
}

bool isPalindrome(int x) {
    
    if(x < 0) {
        return false;
    }
    
    int number = getdigitnumber(x);
    
    if(number == 0) {
        return true;
    }
    
    for(int i = 0; i < ceil((double)number/2); i++) {
        if((x / (int)pow(10, number-i)) % 10 != (x / (int)pow(10, i)) % 10) {
            return false;
        }
    }
    
    return true;
}