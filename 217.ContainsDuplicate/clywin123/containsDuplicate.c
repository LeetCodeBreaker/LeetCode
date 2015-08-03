#include<stdio.h>
#include<stdlib.h>
int cmp( const void* a, const void* b){
	int* A = (int*) a;
	int* B = (int*) b;
	if( *A < *B ) return -1;     
	else if( *A == *B ) return 0;
	else return 1;
	return 0;
}
bool containsDuplicate(int* nums, int numsSize) {
	int i,tmp;
	bool flag=false;
	qsort(nums,numsSize,sizeof(int),cmp);
	tmp = nums[0];
	for(i=1;i<numsSize;i++){
		if(tmp==nums[i]){
			flag=true;
			break;
		}
		tmp = nums[i];
	}
	return flag;
}
