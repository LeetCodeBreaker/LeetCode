class Solution:
    # @param nums, an integer[]
    # @return an integer
    def findPeakElement(self, nums):
        if(len(nums)<=1):
            return 0
        peak = nums[0]
        for i in range(1,len(nums)):
            if(peak<nums[i]):
                peak = nums[i]
            else:
                return i-1
        return i
        
