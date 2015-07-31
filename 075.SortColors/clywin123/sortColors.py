class Solution:
    # @param {integer[]} nums
    # @return {void} Do not return anything, modify nums in-place instead.
    def swap(self,a,b,nums):
        tmp = nums[a]
        nums[a] = nums[b]
        nums[b] = tmp
        return
    def sortColors(self, nums):
        count = 0
        for num in nums:
            for i in range(count,0,-1):
                if(nums[i]<nums[i-1]):
                    self.swap(i,i-1,nums)
            count += 1
        return 
