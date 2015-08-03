int titleToNumber(char* s) {
	int i,answer=0,digit=1;
	for(i=strlen(s)-1;i>=0;i--){
		answer += (digit*(s[i]-64));
		digit *= 26;
	}
	return answer;
}
