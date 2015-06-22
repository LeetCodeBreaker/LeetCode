/*8ms*/
char* convert(char* s, int numRows) {
    int len  = strlen(s);
	char* result = (char *) malloc(sizeof(char)*(len+1));
	result[len]='\0';
	int group = numRows*2 - 2;
	if(group==0) group=1;
	int k = 0;
	for(int i=0, row=0; i<len; i++,row++)
	{
		//new line
		if(group*row+k>=len)
		{
			row=0;
			k++;
		}
		
		result[i] = s[group*row+k];
		if(k!=0 && group*(row+1)-k<len && group!=2*k && i+1<len)
		{
			i++;
			result[i] =s[group*(row+1)-k];
		}
		
	}
	return result;
}