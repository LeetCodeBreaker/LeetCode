/*4ms*/
int reverse(int x) {
    int result = 0;
	while(true)
	{
		if(result>0 && result>(INT_MAX-x%10)/10)
		{
			result = 0;
			break;
		}
		else if(result<0 && result<(INT_MIN-x%10)/10)
		{
			result=0;
			break;
		}
		result = result * 10 + x % 10; 
		x /= 10;
		
		if(x == 0)
			break;
	}
	return result;
}