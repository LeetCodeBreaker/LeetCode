class Solution:
    # @param {float} x
    # @param {integer} n
    # @return {float}
    def myPow(self, x, n):
        def _myPow(x,n):
            if(n==0):
                return 1
            tmp = self.myPow(x,n/2)
            if(n%2==0):
                return tmp*tmp
            else:
                return x*tmp*tmp
        if(n>=0):
            return _myPow(x,n)
        else:
            answer = _myPow(x,n*(-1))
            return 1/float(answer)
