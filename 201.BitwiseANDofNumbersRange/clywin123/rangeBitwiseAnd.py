class Solution:
    # @param {integer} m
    # @param {integer} n
    # @return {integer}
    def rangeBitwiseAnd(self, m, n):
        powof2 = 0
        for i in range(32):
            if((m>>i)&1==1):
                powof2 = i
        lower =  int(math.pow(2,powof2))
        upper =  lower*2
        if(m >= lower and n<upper):
            answer = n
            for i in range(m,n):
                answer = answer&i
            return answer
        else:
            return 0
