class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def maxSubArray(self, nums):
        tmp = [nums[0]]
        i = 0
        for num in nums:
            if(not i):
                i +=1
                continue
            tmp.append(max(tmp[i-1]+num,num))
            i +=1
        return max(tmp)
