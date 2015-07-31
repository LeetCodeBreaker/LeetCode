int numTrees(int n) {
	int array[100]={0},i,j,count;
	array[0]=1;
	array[1]=1;
	for(i=2;i<=n;i++){
		count = 0;
		for(j=0;j<i;j++){
			count += (array[j]*array[i-j-1]);
		}
		array[i]=count;
	}
	return array[n];
}
