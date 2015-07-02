char* convert(char* s, int numRows) {
        
	if(numRows == 1) {
		return s;
	}
	
	int i=0, row=0;
	int headortail = 0;
	int len = strlen(s);
	char *ans = (char*)malloc(numRows*(len+1));
	char *res = (char*)malloc((len+1));
	memset(ans, 0, numRows*(len+1));
	memset(res, 0, (len+1));
	int *strindex = (int*) malloc(numRows*sizeof(int));
	memset(strindex, 0, numRows*sizeof(int));
	for(i = 0; i < len; i++)
	{
		ans[row*(len+1) + strindex[row]] = s[i];
		strindex[row]++;
		if(!headortail) {
			row++;
		}
		else {
			row--;
		}
		if(row%(numRows-1) == 0) {
			headortail = !headortail;    
		}
	}
	
	for(int i = 0, k = 0; i < numRows*(len+1); i++) {
		if(ans[i]!=0){
			res[k] = ans[i];
			k++;
		}
	}
	return res;

}