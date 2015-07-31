class Solution:
    # @param {integer[]} nums
    # @param {integer} val
    # @return {integer}
    def removeElement(self, nums, val):
        number = len(nums)
        for i in range(number):
            if(i>len(nums)-1):
                break
            length = len(nums)
            for j in range(length-1,-1,-1):
                if(nums[j]==val):
                    nums.pop()    
                else:
                    break
            if(i<len(nums) and nums[i]==val):
                nums[len(nums)-1],nums[i]=nums[i],nums[len(nums)-1]
        return len(nums)
