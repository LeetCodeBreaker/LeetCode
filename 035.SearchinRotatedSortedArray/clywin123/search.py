class Solution:
    # @param {integer[]} nums
    # @param {integer} target
    # @return {integer}
    def search(self, nums, target):
        if target in nums:
            return nums.index(target)
        return -1
        
