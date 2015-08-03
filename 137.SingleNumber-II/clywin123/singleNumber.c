int singleNumber(int* nums, int numsSize) {
    int answer=0, bit[32]={0},i,j;
	for(i=0;i<numsSize;i++){
		for(j=0;j<32;j++){
			bit[j]+= (nums[i]>>j)&1;
		}
	}
	for(j=0;j<32;j++){
		if(bit[j]%3==0){
			bit[j]=0;
		}
		else{
			bit[j]=1;
			answer += (bit[j]<<j);
		}
	}
	return answer; 
}
