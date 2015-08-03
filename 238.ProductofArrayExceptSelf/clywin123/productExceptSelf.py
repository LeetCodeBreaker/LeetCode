class Solution:
    # @param {integer[]} nums
    # @return {integer[]}
    def productExceptSelf(self, nums):
        product = 1
        flag = False
        for num in nums:
            if(num==0 and flag ==False):
                flag =True
                continue
            else:
                product *= num        
        if(flag):
            answer = []
            for num in nums:
                if(num):
                    answer.append(0)
                else:
                    answer.append(product)
            return answer
        return [(product/i) for i in nums]
