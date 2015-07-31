import sys
class Solution:
# @param {integer} x
# @return {integer}
    def reverse(self, x):
        flag = 0
        if (x<0):
            flag = 1
            x = x * (-1)
        rev = 0
        carry = 1
        for i in  str(x):
             rev += (int(i)*carry)
             carry *= 10
        if(flag):
            rev *= (-1)
        if(rev > 2147483647 or  rev<-2147483648):
            return 0
        return rev
