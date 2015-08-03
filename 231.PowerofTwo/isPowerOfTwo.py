class Solution:
    # @param {integer} n
    # @return {boolean}
    def isPowerOfTwo(self, n):
        if(n&(n-1)==0 and n!=0):
            return True
        else:
            return False
        
