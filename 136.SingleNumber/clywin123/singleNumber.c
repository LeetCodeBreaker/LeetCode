int singleNumber(int* nums, int numsSize) {
int answer=0,i=0;
	for(i=0;i<numsSize;i++){
		answer = answer ^ nums[i];
	}
	 return answer;  
}
