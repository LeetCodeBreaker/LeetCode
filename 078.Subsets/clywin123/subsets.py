class Solution:
    # @param {integer[]} nums
    # @return {integer[][]}
    def subsets(self, nums):
        answer = []
        for n in range(int(math.pow(2,len(nums)))):
            rev = []
            rev = [(n>>i)&1 for i in range(32)]
            tmp = []
            i = 0
            for m in rev:
                if(m!=0):
                    tmp.append(nums[i])
                i+=1
            tmp = sorted(tmp)
            answer.append(tmp)
        return answer
