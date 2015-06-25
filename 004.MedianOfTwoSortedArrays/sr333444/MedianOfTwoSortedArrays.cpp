class Solution {
public:
    int getNext(vector<int>& nums1, vector<int>& nums2)
{
	int result;
	if(nums1.size()==0)
	{
		result = nums2.back();
		nums2.pop_back();
	}
	else if(nums2.size()==0)
	{
		result = nums1.back();
		nums1.pop_back();
	}
	else if(nums1.back()<nums2.back())
	{
		result = nums2.back();
		nums2.pop_back();
	}
	else
	{
		result = nums1.back();
		nums1.pop_back();
	}
	return result;
}
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int len = nums1.size() + nums2.size();
	if(len % 2 == 0)
	{
		int median1;
		for(int i=0; i<len/2; i++)
		{
			median1 = getNext(nums1, nums2);
		}
		int median2 = getNext(nums1, nums2);
		return (double) (median1+median2)/2;
	}
	else
	{
		int median;
		for(int i=0; i<len/2+1; i++)
		{
			median = getNext(nums1, nums2);
		}
		return median;
	}
    }
};