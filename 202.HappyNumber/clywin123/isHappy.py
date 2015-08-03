class Solution:
    # @param {integer} n
    # @return {boolean}
    def isHappy(self, n):
        visit = [n]
        num = n
        while(num!=1):
            digit = []
            digit = [int(i) for i in str(num)]
            newnum = 0
            for tmp in digit: 
                newnum += tmp*tmp
            if(newnum in visit):
                return False
            print num,newnum
            num = newnum
            visit.append(num)
        return True
