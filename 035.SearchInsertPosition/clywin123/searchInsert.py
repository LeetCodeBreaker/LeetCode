class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer}
    def searchInsert(self, nums, target):
        for tmp in nums:
            if(tmp>=target):
                return nums.index(tmp)
        return len(nums)
