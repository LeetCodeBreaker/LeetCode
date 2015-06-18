bool isDuplication(char* s, int start, int end)
{
	int total[256] = {0};
	for(int i=start; i<end; i++)
	{
		total[s[i]]++;
	}
	for(int i=0; i<256; i++)
	{
		if(total[i]>1)
			return true;
	}
	return false;
}

int lengthOfLongestSubstring(char* s) {
    int len = strlen(s);
	int maxLen = 0;
	for(int i=0, j=1; j<=len;)
	{
		if(isDuplication(s, i, j))
		{
			i++;
		}
		else 
		{
			if(j-i>maxLen)
				maxLen = j-i;
			j++;
		}
	}
	return maxLen;
}