class Solution:
    # @param {integer[]} nums
    # @return {integer}
     def majorityElement(self, nums):
        nums.sort()
        return nums[len(nums)/2]
        
