import copy
class Solution:
    def _permute(self,nums,length,answer):
        if(length==len(nums)-1):
            answer.append(copy.deepcopy(nums))
            return
        for i in range(length,len(nums)):
            nums[i],nums[length] = nums[length],nums[i]
            self._permute(nums,length+1,answer)
            nums[i],nums[length] = nums[length],nums[i]
        return

    def permute(self, nums):
        length = len(nums);
        answer = []
        self._permute(nums,0,answer)
        return answer
        
