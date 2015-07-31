class Solution:
    # @param {integer} n
    # @return {integer}
    def climbStairs(self, n):
        if(n<0):
            return 0
        stair = [1,1]
        for i in range(2,n+1):
            stair.append(stair[i-1]+stair[i-2])
        return stair[n]
        
