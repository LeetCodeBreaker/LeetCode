int getNext(int* nums1, int* nums1Size, int* nums2, int* nums2Size)
{
	if(*nums1Size == 0)
	{
		(*nums2Size)--;
		return 2;
	}
	else if(*nums2Size == 0 || nums1[*nums1Size-1]>nums2[*nums2Size-1])
	{
		(*nums1Size)--;
		return 1;
	}
	else 
	{
		(*nums2Size)--;
		return 2;
	}
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
	int len = nums1Size + nums2Size;
	//even
	if(len % 2 == 0)
	{
		for(int i=0; i<len/2-1; i++)
		{
			getNext(nums1,&nums1Size, nums2, &nums2Size);
		}
		int median1, median2; 
		if(getNext(nums1,&nums1Size, nums2, &nums2Size)==1)
			median1=nums1[nums1Size];
		else
			median1=nums2[nums2Size];
		if(getNext(nums1,&nums1Size, nums2, &nums2Size)==1)
			median2=nums1[nums1Size];
		else
			median2=nums2[nums2Size];
		return (double) (median1+median2)/2;
	}
	else
	{
		int median;
		for(int i=0; i<len/2; i++)
		{
			getNext(nums1,&nums1Size, nums2, &nums2Size);
		}
		if(getNext(nums1,&nums1Size, nums2, &nums2Size)==1)
			return nums1[nums1Size];
		else
			return nums2[nums2Size];
	}
}
