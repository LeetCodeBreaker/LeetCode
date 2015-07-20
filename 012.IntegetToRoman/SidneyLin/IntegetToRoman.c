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

typedef struct _Roman
{
    int value;
    char *letter;
}Roman;

void settable(Roman* ary)
{
    ary[0].value = 1;
    ary[0].letter = "I";
    ary[1].value = 5;
    ary[1].letter = "V";
    ary[2].value = 10;
    ary[2].letter = "X";
    ary[3].value = 50;
    ary[3].letter = "L";
    ary[4].value = 100;
    ary[4].letter = "C";      
    ary[5].value = 500;
    ary[5].letter = "D";        
    ary[6].value = 1000;
    ary[6].letter = "M";            
    
}
char* intToRoman(int num) {
    int ary[4] = {-1};
    char *ans;
    if(num == 0) {
        return NULL;
    }
    
    Roman *table = (Roman*)malloc(7*sizeof(Roman));
    if(table == 0) {
        return NULL;
    }
    
    settable(table);
    
    int dig = getdigitnumber(num);
    
    ary[0] = num % 10;
    ary[1] = (num /10) % 10;
    ary[2] = (num /100) % 10;
    ary[3] = (num /1000) % 10;
    
    for(int i = dig+1 ; i < 4; i++) {
        ary[i] = -1;
    }
    
    
    ans = malloc(150*sizeof(char));
    memset(ans, 0, 150);
    
    for(int i = 3; i >=0; i--) {
        int j = 2*i;
        if(ary[i]>=0 && ary[i] <=3) {
            for(int k = 0; k < ary[i]; k++) {
                strcat(ans, table[j].letter);
            }
        }
        else if(ary[i] == 4) {
            strcat(ans, table[j].letter);
            strcat(ans, table[j+1].letter);
            
        }
        else if(ary[i] == 5) {
            strcat(ans, table[j+1].letter);
        }
        else if(ary[i] > 5 && ary[i] <= 8) {
            strcat(ans, table[j+1].letter);
            for(int k = 0; k < ary[i] - 5; k++) {
                strcat(ans, table[j].letter);
            }
        }
        else if(ary[i] == 9) {
            strcat(ans, table[j].letter);
            strcat(ans, table[j+2].letter);
        }
    }
    
    return ans;
    
}