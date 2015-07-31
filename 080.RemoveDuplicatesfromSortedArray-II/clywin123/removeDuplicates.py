class Solution:
    # @param {integer[]} nums
    # @return {integer}
    def removeDuplicates(self, nums):
        if(not nums):
            return 0
        pointer = 1
        previous = nums[0]
        twice = True  #
        for i in range(1,len(nums)):
            if(nums[i]==previous and twice):#
                nums[i],nums[pointer] = nums[pointer],nums[i]
                pointer += 1#
                twice = False#
            if(nums[i]!=previous and nums[i]>previous):
                previous = nums[i]
                nums[i],nums[pointer] = nums[pointer],nums[i]
                pointer +=1
                twice = True#
        #print nums[:pointer]
        return pointer
