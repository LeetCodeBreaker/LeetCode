int maxArea(int* height, int heightSize) {
    int max = 0;
    int head = 0;  
    int tail = heightSize-1;  

    while(1)  
    {  
        int min = 0;
        int vol = 0;
        
        if(height[tail] > height[head]) {
            min = height[head];
        }
        else {
            min = height[tail];
        }
        
        vol =  min * (tail-head);  
        if(vol > max) {
            max = vol;
        }
        
        if(height[head] < height[tail]) {  
          head++;  
        }  
        else {  
          tail--;  
        }
        
        if(head > tail) {
            break;
        }
    }
    return max;  
}