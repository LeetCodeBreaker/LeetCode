/*4ms*/
int myAtoi(char* str) {
	int len = strlen(str);
	int result=0;
	bool bNegative = false;
	int i=0;

	//skip whitespace
	while(str[i]==' ')
	{
		i++;
	}

	//check negative
	if(str[i] == '-')
	{
		bNegative = true;
		i++;
	}
	else if(str[i] == '+')
	{
		i++;
	}


	for(; i<len; i++)
	{
		if(str[i]>'9'||str[i]<'0')
			break;
		if(bNegative)
		{
			if(result < (INT_MIN + (str[i]-'0'))/10)
				return INT_MIN;
			result = result*10 - (str[i]-'0');
		}
		else 
		{
			//check overflow
			if(result > (INT_MAX - (str[i]-'0'))/10)
				return INT_MAX;
			result = result*10 + (str[i]-'0');
		}
		
	}
	return result;
}